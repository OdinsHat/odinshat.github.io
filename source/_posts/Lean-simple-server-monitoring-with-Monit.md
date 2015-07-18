title: "Lean, simple server monitoring with Monit"
date: 2015-07-11 07:39:24
tags:
---

[Monit](https://mmonit.com/monit/) is a comparitively lightweight server monitor. I'd say its biggest sellig point is th ease ans sped of setup compared to the more enterprise-grade monnitoring services like [Nagios](http://nagios.org), [Icinga](http://icinga.org), [Munnin](http://munin-monitoring.org/), [Zabbix](http://www.zabbix.com/), etc. Those are likely overkill unless in an enterprise situation.

Although I say comparitively lightweight you'll find as you dig into Monit it has a great depth of features. I came to use it recently because a problem I've recently run into with PHP-FPM dying for no apparent reason leaving me with a bad gateway timeout for nginx.

Monit to the rescue which will detect the dead service, restart it, log it and continue monitoring.

## Install

This assumes you're running Ubuntu/Debian in all the following but you should be able to adapt it for your own distro.

{% codeblock %}
sudo apt-get update
sudo apt-get install monit
{% endcodeblock %}

After Monit is installed go ahead and use your fave editor (Vim obviously) and edit monits config file:

## Basic Setup

{% codeblock %}
sudo vim /etc/monit/monitrc
{% endcodeblock %}

There's a few key things you'll want to change in here and a few that are optional but the config file is great with loads of explanation on each variabe you can change.

{% codeblock /etc/monit/monitrc %}

# Checks pocesses every 2 minutes (120 secs) for up state
set daemon 120

# Use the localhost as the mailserver for sending alerts (change as appropriate)
set mailserver localhost

# The email address to send alerts of services being dwn and restarted
set alert your@email.com

{% endcodeblock %}


## Service Monitoring
Service monitoring is just one of the many core facets of Monit but its the one I'm focussing on in this blog. Even within basic service monitoring there's a lot extra options you can use but I'm keeping it simple for now. If you want to go into more detail such as file checking, space, network monitoring, etc check out the [full manual at monit HQ](https://mmonit.com/monit/documentation/monit.html).

Heres a very basic example for checking 3 services on yoru box:

{% codeblock /etc/monit/monitrc %}

###############################################################################
## Services
###############################################################################
check process php5-fpm with pidfile /var/run/php5-fpm.pid
    start program = "/etc/init.d/php5-fpm start"
    stop program = "/etc/init.d/php5-fpm stop"
check process nginx with pidfile /var/run/nginx.pid
    start program = "/etc/init.d/nginx start"
    stop program = "/etc/init.d/nginx stop"
check process mysql with pidfile /var/run/mysqld/mysqld.pid
    start program = "/etc/init.d/mysql start"
    stop program = "/etc/init.d/mysql stop"
{% endcodeblock %}

Afer doing any changes to the monitrc file you must run:

{% codeblock %}
sudo monit reload
{% endcodeblock %}

## Web Interface

If receiving notifications and allowing Mnit to do its thing isn't enough then you can satisfy your inner voyeur by setting up the Monit httpd service. In the monitc file find the commented out section below:

{% codeblock /etc/monit/monitrc %}

# set httpd port 2812 and
#    use address localhost  # only accept connection from localhost
#    allow localhost        # allow localhost to connect to the server and
#    allow admin:monit      # require user 'admin' with password 'monit'
#    allow @monit           # allow users of group 'monit' to connect (rw)
#    allow @users readonly  # allow users of group 'users' to connect readonly

{% endcodeblock %}

The comments make it pretty self explanatory but to give you an idea I've included a simple example here:

{% codeblock /etc/monit/monitrc %}
set httpd port 2500 and         # The port to allow access from
   use address 101.102.103.104   # Your servers IP address to bind to
   allow 89.90.91.92            # Your IP address
   allow username:password
   allow @monit
   allow @users readonly
{% endcodeblock %}

With those settings you can visit `http://101.102.103.104:2500` and after putting in the username and password above you will be presented with something like this:


{% asset_img monit-screen.png Monit Web GUI %}



## Going Further

This really only scractes the surface of what Monit can do as you may have noticed with the huge number of examples and sub-rules to checks in the monitrc file. I'd strongly recommend reading through the config file and checking out the manual too for some of Monits more powerful features.

## Troubleshooting

### Problem 1 - Missing PID files

If you find your MySQL server doesn't have a pid file (one of my servers didn't) then its as simple as adding it to your config file (in MySQL's case: /etc/mysql/my.cnf) like so:

{% codeblock %}
pid-file    = /var/run/mysqld/mysqld.pid
{% endcodeblock %}

Then set the location of that pid file in your server monitoring configs as above.

### Problem 2 - Alert emails not working

This is pretty common especially if you're using the localhost. Its most likely they are going to spam or your server is simply picking them up due to a misconfigured Postfix install. Check your spam folder and try a different alert email on a different domain to narrow down the issue.
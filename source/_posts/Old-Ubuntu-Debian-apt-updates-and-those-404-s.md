title: "Old Ubuntu/Debian apt updates and those 404's"
date: 2015-07-11 06:42:27
tags: 
  - ubuntu
  - linux
---

If like me you have had annoying 404's pop up during `apt-get update` and no amount of fiddling with the `/etc/apt/source.list` then it means your Ubuntu has reached End of Life. AKA: it's an <acronym title="Old Aged Pensioner">OAP</acronym>. 

It needs a bus pass.

So to help it out simply change all instances of `archive.ubuntu.com` and `security.ubuntu.com` to `old-releases`. Like so:

{% codeblock /etc/apt/source.list %}
# From this:
#deb http://archive.ubuntu.com/ubuntu quantal main
#deb http://archive.ubuntu.com/ubuntu quantal-updates main
#deb http://security.ubuntu.com/ubuntu quantal-security main
#deb http://archive.ubuntu.com/ubuntu quantal universe
#deb http://archive.ubuntu.com/ubuntu quantal-updates universe

# To this:
deb http://old-releases.ubuntu.com/ubuntu quantal main
deb http://old-releases.ubuntu.com/ubuntu quantal-updates main
deb http://old-releases.ubuntu.com/ubuntu quantal-security main
deb http://old-releases.ubuntu.com/ubuntu quantal universe
deb http://old-releases.ubuntu.com/ubuntu quantal-updates universe
{% endcodeblock %}

Then run `sudo apt-get update` to get the 'fresh' list of packages you're used to But its highly recommended you upgrade your distro to a more up-to-date version by following the steps at [Ubuntu's community EOL page](https://help.ubuntu.com/community/EOLUpgrades/).
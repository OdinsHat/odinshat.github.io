title: 'Useful Ansible one-liners (AKA: Ad-hoc commands)'
date: 2015-10-17 03:26:46
tags:
  - sysadmin
  - ansible
  - devops
  - linux
---

You need to execute a single command across multiple servers? You may use Ansible but that’s mainly about playbooks, provisioning, setup and the like isn't it?

Not so.

Having been using [Ansible](http://www.ansible.com/) for a couple of years I thought it about time I started using the ad-hoc commands.

In the past I used Fabric for executing SSH commands across multiple hosts but now Ansible fills that role nicely.

{% asset_img ansible-transparent-logo.png Ansible Logo %}

Below is a quick list of some Ansible one-liners:

### Update Your Apt Cache and Upgrade
1. `ansible main -i ./hosts -m apt -a "update_cache=yes upgrade=safe"`

2. `ansible centosserver -i ./hosts -m yum -a 'name=* state=latest'`

You’re not limited by OS with Ansible. Here I’m using both the Apt and Yum command modules to update all packages.

### Restart Your Webserver
1. `ansible 192.168.0.1 -m service -a 'name=nginx state=restarted'`

2. `ansible main -i ./hosts -m service -a 'name=apache2 state=restarted'`

I’ve given 2 examples above to show:
1. That you can reference a host directly on the terminal.
2. It works for any service

### Deploy a Git Repo
`ansible webservers -m git -a "repo=git://example.com/epicapp.git dest=/srv/epicapp version=HEAD”`

*If Knowledge is what you want*
This will give you a JSON output of all your servers and a huge amount of information on each:
`ansible all -m setup`

The above assumes you have your hats file in the default location or defined somewhere.

## Useful Ansible Links
1. [Official Ansible Docs](http://docs.ansible.com/ansible/intro.html)
2. [Ansible Video Tutorial Series](https://codereviewvideos.com/course/ansible-tutorial)

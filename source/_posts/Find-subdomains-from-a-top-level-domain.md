title: Find subdomains from a top level domain
date: 2016-01-10 01:22:01
tags:
 - dns
 - networking
---

Having been asked this question a few times by varying people I thought I’d do a quickie blog post on how to find subdomains for a domain.

## The Official Way

`dig @ns.thenameserver.net example.com axfr`AXFR is a method of domain transfer and if the name servers are configured to allow the command to be executed then it would give you the full NS record for that domain including any subdomains.

Trying that will likely give you this message:```; <<>> DiG 9.8.3-P1 <<>> @ns.thenameserver.net example.com axfr; (1 server found);; global options: +cmd; Transfer failed.```

## Unofficial Methods

* **[SubBrute Python Script](https://github.com/TheRook/subbrute)** - a Python script that uses a dictionary to brute force lookup subdomains for a given domain.

* **[Fierce2 Perl Script](http://ha.ckers.org/fierce/)** - similar to SubBrute but with a smaller dictionary and anecdotally lower. Still worth a look.

* **[Reverse IP Domain Check](http://www.yougetsignal.com/tools/web-sites-on-web-server/)** - This will give you domains on the same server some of which may be subdomains of the URL your targeting.

* **Google with the following query site:example.com** - This may or may not retrieve subdomains of the main domain

* **Finally this website:** [https://pentest-tools.com/reconnaissance/find-subdomains-of-domain](https://pentest-tools.com/reconnaissance/find-subdomains-of-domain)

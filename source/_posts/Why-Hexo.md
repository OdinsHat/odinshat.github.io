title: "Why Hexo?"
date: 2015-05-12 21:58:25
tags: hexo
---

{% asset_img hexo-logo.png [Hexo Logo] %} It's taken a lot of umming and aring to come to this decision but it 
was finally made when I decided I'd had enough of said umming and arring.

My basic requirement was: 
**A site hosted on Github generated using a static site generator with posts written in Markdown.**

### Simple?
Well I'd narrowed it down to [Jekyll](http://jekyllrb.com/) and [Pelican](http://blog.getpelican.com/) initially.

### Why not Jekyll
Jekyll is hugely popular and if you check out my links below it is by far the biggest static site generator out there. However, I was slightly biased against precisely because of its popularity. Sometimes I prefer the underdog and Jekyll was too popular, too obvious.

Another reason was I wanted to avoid muddying the waters of my Python knowledge by taking on a Ruby driven generator. I'd worked with Ruby liberally in the past with one main site built using Rails and an API endpoint in Padrino about 4or so years ago. Even turned my old blog into [Mephisto](http://stackoverflow.com/questions/4609821/what-happened-to-mephisto) temporarily at ne point. I wanted to try something new-ish in a way.
I know I can avoid the Ruby side of it and simply use as is but I wanted to eventually get my hands dirty in ehatever I was using. That ruled out any Ruby-based generator - including the next most popular [Octopress](http://octopress.org), which again didn't interest me much.

### Why not Pelican?
Apart from the ugly as hell project blog which doesn't really sell itself?

<img src="{% asset_path "pelican-blog.png" %}" alt="Pelican Blog Screnshot" />

I do use [Pelican](http://blog.getpelican.com/) for another site and its been gathering dust. Its not intuitive to use although slowly improving over time it was messy to deploy and setup. You could either use [Fabric](http://www.fabfile.org/) (great, I've used Fabric extensively in the past) or the Makefile that it generated. It turns out the Makefile method often had better results. Though generating posts was still slower and messier than I'd have liked. Nothing seemed polished and for a static site gen 5 years old I expected better.

I went through several iterations that never saw the light of day. First it required I set up a virtualenv, install Pelican, then its dependencies, etc, etc, etc. I was fiddling around trying to make a nice custom theme because all the existing themes weren't to my liking. This was completly different to the days of my first tech blog where I just chose whatever Worpress theme looked nice at the time and I changed with the changing of the seasons. Pelican had no nice default themes and was a pain to use.

I simply wanted somewhere to write - I didn't want to fight to write.
<aside>
Summary of Why:
* Clean, simple CLI.
* Comprehensive.
* Just different enough.
* Nice site.
* Chance to dabble in EJS, Node, etc.
</aside>
So on I went considering even hosted blogs like Tumblr, Wordpress, Blogger. I started looking at other dev blogs to see what they used and quickly noticed many of them had the same feelings I did. 

No custom themeing (or very little). Often 3rd party hosted on 3rd party platforms. 

I found the following two sites invaluable and visited them repeatedly:

* [https://www.staticgen.com/](https://www.staticgen.com/)
* [https://staticsitegenerators.net/](https://staticsitegenerators.net/)

It was after some time I noticed a new(-ish) monster on the horizon by the name of [Hexo](http://hexo.io). Cool name, clean site, oh - what this. Holy shit deployment to die for. So simple - I Just add "git" to the config file? Seriously?!

All using custom terminal and based off JS/Node?

Its packages and plugins easily available via npm. For something so relatively young it offered a hell of a lot and in a very slick package.

And so here's to a hopefully bright future with Hexo.

<aside>I'll be converting my other blog to Hexo in the not too distant future also.</aside>
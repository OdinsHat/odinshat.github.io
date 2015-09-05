title: Hexo Deezer Tag Plugin
date: 2015-07-19 14:17:59
tags:
  - hexo
  - javascript
  - projects
---

As a relatively new user to Hexo I thought it only right to put my contrbution into the mix with a new plugin. I was inspired by [Ivanov Yordan's Spotify tag plugin here](https://github.com/ivanovyordan/hexo-tag-spotify).

The [Deezer Tag Plugin](https://github.com/OdinsHat/hexo-tag-deezer).

It enables you to use a tag like this:

```
{% deezer trackid %}
```

To get something like this in your blog post:

{% deezer 916445 %}

Or maybe you want it square?

{% deezer 1109731 square %}

I'm planning to add support for the Deezer HTML5 widget at a later date. The current version uses the iframe plugin and if you're interested in what the full widgets are cacapble of without using short tag plugins like this then checkout the [Deezer widget page](http://developers.deezer.com/musicplugins/player?type=tracks&id=68515055).

However, the advantages with this:

* Integration with Hexo.
* Easy to put a track in your post.
* Less HTML cruft to deal with. Just a nice tidy tag.

Checkout the [Github repo for info on installation and usage](https://github.com/OdinsHat/hexo-tag-deezer).
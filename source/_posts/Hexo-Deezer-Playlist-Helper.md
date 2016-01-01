title: Hexo Deezer Playlist Helper
date: 2015-12-31 11:55:29
tags:
  - hexo
  - javascript
  - projects
---

If you're looking for a way to add configurable Deezer playlists to your Hexo blog then check out this helper.

This is my latest addition to the ecosystem: **The Hexo Deezer Playlist Helper**.

According to [Hexo docs Helpers are](https://hexo.io/docs/helpers.html):

> used in templates to help you insert snippets quickly. Helpers cannot be used in source files.

So, they are good for adding widgets to your sidebar such as playlists, Twitter feeds, ad widgets, etc.
I'd already created a Hexo tag for showing a Deezer tracks but wanted to:

1. Create a site widget that was more longterm.
2. Create something other than a tag - as a new challenge and add something new to Hexo.

So it seemed only natural to create this plugin as a helper.

It would be pretty easy to convert into a tag and anyone is free to do that - [check out the repo](https://github.com/OdinsHat/hexo-deezer-playlist-helper).

You can see the helper in action to the right -->


### Currently listening to...

{% deezer 585030 %}
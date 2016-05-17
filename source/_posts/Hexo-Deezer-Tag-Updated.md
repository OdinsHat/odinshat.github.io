title: Hexo Deezer Tag Updated
date: 2016-05-17 05:24:30
tags:
 - hexo
 - continuous integration
 - ci
 - testing
 - projects
 - programming
---

<img src="{% asset_path "hexo-logo.png" %}" alt="Hexo Logo" class="pull-right" /></a> Version 1.0.6 has been released of the latest [Hexo Deezer Tag plugin](http://www.dougbromley.com/2015/07/Hexo-Deezer-Tag-Plugin/). This was mainly a maintenance update to include the latest changes in Hexo by [Tommy351](https://github.com/tommy351). These included [project-specific styling](https://github.com/hexojs/jscs-preset-hexo) and [linting](https://github.com/hexojs/eslint-config-hexo).

<br style="clear:both" />

## Changes

 * Adding linting (using [eslint](http://eslint.org/)) and [JS source style checking](http://jscs.info/) based on Hexo's own configs to the build process.
 * Travis CI for Node 0.12, 4, and 5 along with associated badge to README.
 * Adding [Appveyor continuous integration](https://ci.appveyor.com/project/OdinsHat/hexo-tag-deezer/) testing and badge to show status in README file.

> I'm a big believer in uniformity of coding styles within projects and its associated extensions and think it important that core projects standards overrule your own personal views.

## Using Changes

As this is mainly a change to the development of the plugin you won't be able to see any changes to the plugin on your site. It just makes the plugin a little more robust, clearly displaying status and preparing for some major refactoring to implement proper testing of the plugin (using [Mocha](https://mochajs.org/)) along the lines of my other Hexo extension the [Hexo Deezer Playlist Helper](https://github.com/OdinsHat/hexo-deezer-playlist-helper) for templates.

The changes will be immediately noticeable on the Deezer Tag page. But you can also check them by cloning the repo and running the npm commands:

```
git clone https://github.com/OdinsHat/hexo-tag-deezer.git
cd hexo-tag-deezer
npm install
npm run eslint
npm run jscs
```

## Finally

{% deezer 16541039 %}
**Grimes is currently touring!**
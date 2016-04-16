title: Using tmux and tmuxinator to organise projects
date: 2016-04-16 00:32:15
tags:
 - programming
 - open source
---
If you're anything like me and have a problem with names - not just people - but projects too. Or if you find yourself losing track of projects because of different languages or editors used.

> You may find your saviour in the tmux + tmuxinator combo.

When discovering [virtualenvwrappers](https://virtualenvwrapper.readthedocs.org/en/latest/) `workon` command for managing Python projects I was immediately envious of it's functionality; wishing it was available for other projects.

I wanted a similar app that could launch prepared editor environments. While being flexible enough to change editor on a whim. I often switch between Vim, Sublime and Atom depending on mood and weather. If I'm feeling especially masochistic I'll setup a project in PHPStorm (leave hate mail below). 

Next, something that could store my code locations as I had several. Including `~/Dev` `~/Development` `~/Sites` - don't ask me why. But also remote locations accessible only via FTP, SSH or some other arcane method.

Now with anything from 2 big to 20 small projects on the go for work and around 20-30 small home/hobby projects its not suprising I got muddled.

In my idle wandering I came across the aforementioned **tmuxinator** which ticked ALL the boxes using a tool I already used (tmux).

## tmux
[tumx](https://tmux.github.io) is like Screen but 10x better. If you're still using Screen then switch to tmux. If you've never heard of Screen then...pretend I said nothing and use tmux!

tmux enables you to save multiple virtual consoles. In a basic way it can help you save your place in an terminal session. This is great for unstable SSH connections. If the session dies then normally you lose everything including spawned processes, etc. 

But if you were in a tmux session then its all saved as ts all executed from the tmux process. tmux becomes more profound as you use it. When you combine it with [Tmuxinator](https://github.com/tmuxinator/tmuxinator) you suddenly realise you are capable of taking over the universe (or something similar)

## Tmuxinator
[Tmuxinator](https://github.com/tmuxinator/tmuxinator) gives you all the power of Tmux but with configurable states. So you're no longer restricted to just saving your last state said but you can set up your own states. Your terminal, and to an extent your system, can be setup for a particular project.

<img src="{% asset_path "unlimited-power.gif" %}" alt="tmux and tmuxinator gives unlimited power" />

**Put another way it gives you that `workon` used in Python I mentioned earlier with unlimited power.**

Imagine you have my hobby project-nest and you are wondering what to do today with your 30+ hobby projects. Do you want to spend 10, 20, 30, 60, minutes hunting for the one you last worked on about 6 months ago whose name began with p?

Oh god you're sure it was in that folder with other Node experiments maybe or?

You don't have to remember once you've set up a tmuxinator config file in YAML. 

All it takes then is:

```
% mux list

tmuxinator projects:
awin-feeder   fspart   myblog    ukp
```

And all it takes is `mux open myblog` to open up that project. 

Here's an example of the tmuxinator project file for this blog:

```yaml
name: myblog
root: /Users/doug/Sites/dougbromley/blog

windows:
  - editor:
      layout: main-vertical
      panes:
        - subl --project myblog.subliime-project; clear
        - hexo --help
  - genwatcher:
      layout: main-vertical
      panes:
        - hexo generate -w
        - hexo serve
  - gitstats:
      layout: main-horizontal
      panes:
        - git ll
        - git cal
        - git summary
```

In the above its:

1. Opening the a basic vertical layout 
2. Then in the main pane its opening Sublime with my blog as the main project so I can start editing straight away. 
3. In a separate pane the `hexo help` command is run to remind me of hexo's commands. 
4. In another window the hexo local server is run.
5. In that same window another pane with hexo generate is run with the watch flag so I can see changes regenerated live.
6. In the final window is a set of panes giving some git info - I often find this useful to remind me where I left the project.

<img src="{% asset_path "final-screen.png" %}" alt="Session Screenshot of Window gitstats" />

In the past all of these sequences and processes would have to be remembered but if you have multiple projects it can become a burden to remember them all.

[Tmuxinator](https://github.com/tmuxinator/tmuxinator) along with [tumx](https://tmux.github.io) makes things much simpler.
title: Useful Git Aliases
date: 2016-05-01 01:34:08
tags:
 - git
 - programming
---

If I ever start at a new job where I'm given a new Mac I always set up these aliases. I'll list them with their output then at the end provide a gist of them you can add to your own aliases.

If you're on a Mac with OSX then you will find your aliases in `~/.gitonfig`

You can add aliases with the following example:

`$ git config --global alias.co checkout`

Without further a...oh sod that cliche. Here's my aliases:

```
a = add
b = !git for-each-ref --sort='-authordate' --format='%(authordate)%09%(objectname:short)%09%(refname)' refs/heads | sed -e 's-refs/heads/--'
c = commit -m
cob = checkout -b
devs = shortlog -n -e -s
ds = diff --staged
l = log --graph --pretty=format:%C(yellow)%h\ %ad%Cred%d\ %Creset%s%Cblue\ [%cn] --decorate --date=short
ll = log --graph --all --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(bold yellow)— %an%C(reset) %C(bold blue)<%ae>%C(bold red)%d%C(reset)' --abbrev-commit --date=relative
panic = !tar cvf ../git_panic.tar *
rao = remote add origin
s = status -s
tidy = !git gc && git clean -dfx && git stash clear
undo-commit = reset --soft HEAD~1
wdiff = diff --word-diff=plain
who = shortlog -n -e -s
```

Here's a gist of my current aliases:

<script src="https://gist.github.com/OdinsHat/2276396018322e21d5608fcc007cc6c5.js"></script>
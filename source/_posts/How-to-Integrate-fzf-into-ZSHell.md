---
title: How to Integrate fzf into ZSHell
date: 2020-10-28 14:46:49
tags: 
    - zsh
    - shell
    - linux
---

There's 2 simple ways for integrating fzf into your ZShell configuration. The first is shown on the [README](https://github.com/junegunn/fzf#fuzzy-completion-for-bash-and-zsh) of the git repo. Whereby you enter the 
the shown functions and variables into your bashrc or in this case zshrc. However, if you have the ability to install fzf via your package manager (Apt, Pacman, Yum) then fzf should have let you with 2 files to source in your 
.zshrc file. 

The two files you need to source are dependent on your distro but on Arch Linux based distros the files are located at

* /usr/share/fzf/key-bindings.zsh
* /usr/share/fzf/completion.zsh

After a reload of your configuration with threse two sourced files you will get the default fzf functionality. E.g.

```
# Files under current directory
# - You can select multiple items with TAB key
vim **<TAB>

# Files under parent directory
vim ../**<TAB>

# Files under parent directory that match `fzf`
vim ../fzf**<TAB>

# Files under your home directory
vim ~/**<TAB>


# Directories under current directory (single-selection)
cd **<TAB>

# Directories under ~/github that match `fzf`
cd ~/github/fzf**<TAB>
```

By pressing <TAB> after a double asterisk you get a fuzzy finder menu appear under your prompt giving you the most likely possibilities for what you want to open based on your history and location context.

If you're not sure if you have the above files you can do a quick find on the command line:

```sudo find ./ -name key-bindings.zsh```

This may sshow you other plugins but if you just look out for fzf in the path those will be your files.

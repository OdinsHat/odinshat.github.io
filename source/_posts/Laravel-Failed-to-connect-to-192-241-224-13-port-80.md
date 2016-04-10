title: 'Laravel: Failed to connect to 192.241.224.13 port 80'
date: 2016-01-18 19:54:53
tags:
  - laravel
  - php
  - quickfix
  - composer
---
<img src="{% asset_path "quick-fix.png" %}" class="pull-right" />
If you are getting the following error when starting a new project on OSX especially the latest versions:

```
[curl] 7: Failed to connect to 192.241.224.13 port 80: Operation timed out [url] http://192.241.224.13/laravel-craft.zip
```

The simple answer is you are using an old version of Laravel's installer. As of writing this blog it is at version 1.3.1. Even if you have followed the install procedures given on the [Laravel site](https://laravel.com/docs/5.2#installation) you may still be suffering this issue.

Execute this command:

```
% where laravel
```

<img src="{% asset_path "laravel-logo-white.png" %}" />


If the result is something like this `/usr/local/bin/laravel` instead of your local home directory being the first entry then I can guarantee you are running an older version which is overriding the versuin you have installed. Most likely version 1. BNext type this to confirm: `laravel --version`.

```
% laravel --version

Laravel Craft version 1.0.0
```

As you can see it seems on this machine version 1.0.0 is still the one being executed.

To solve the problem simply run `% rm /usr/local/bin/laravel`

Then redo the installation and make sure the new installation is pointed to in your `.bashrc` or `.zshrc` `$PATH` variable.

When you finally get the right version you should see something like this:

```
% laravel --version                                                                                                           

Laravel Installer version 1.3.1
```
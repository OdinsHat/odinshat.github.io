title: 'Error: Cannot find module'
date: 2015-10-17 03:18:31
tags:
 - hexo
---

<img src="{% asset_path "quick-fix.png" %}" class="pull-right" />

Just a quick troubleshooting post for anyone using Hexo at the moment. If you go into your Hexo directory and do any Hexo command but recieve something similar to this:

```
[Error: Module did not self-register.]
{ [Error: Cannot find module './build/default/DTraceProviderBindings'] code: 'MODULE_NOT_FOUND' }
{ [Error: Cannot find module './build/Debug/DTraceProviderBindings'] code: 'MODULE_NOT_FOUND' }
```

Don't worry - it's a really quick fix. Courtesy of [Tommy351](https://github.com/hexojs/hexo/issues/1055#issuecomment-74614630)

Simply type:

```
npm install hexo --no-optional
```

That will get your Hex instakl back up & running no probs.

If you're curious and want to know more checkout [this issue on Github](https://github.com/hexojs/hexo/issues/1055)

### What I'm Currently Listening To

{% deezer 107351082 %}
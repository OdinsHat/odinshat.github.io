---
title: VueJS as Part of the Page
date: 2018-05-17 21:26:16
tags:
 - vuejs
 - vue
 - vuejs 2.0
 - spa
 - SPA
---

In this post I just wanted to show a simple example of how easy it is to include a small part of VueJS 2.0 into a small part of the page. Thats one of the great things about VueJS 2.0. It doesn't have to take over the entire page. It can simply take control of a small section, a button even. Whatever you want.

So here goes. I'm going to create a VueJS 2.0 Hello World app then follow it up with  Gist and a JSFiddle link to the code.

<script src="https://vuejs.org/js/vue.js"></script>

<div id="#app">
    <input type="text" v-on:input="changeAuthorName">
    I, {{ author }}, made this
</div>

<script>
new Vue({
    el: '#app',
    data: {
        author: 'Doug'
    },
    methods: {
        changeAuthorName: function(event) {
            this.title = event.target.value;
        }
    }
});
</script>


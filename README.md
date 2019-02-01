# less wrapper
Do you find yourself doing a `grep -rn` through a code base looking for an given log line or function call, then doing a quick `less <file>.src` followed by a `:382` to jump to the relevant line?

Wouldn't it be nicer if you could just open that line directly using the `grep -rn` output?

The `less` wrapper script intends to do exactly that, a shorthand and intuitive way to open files.

Any of the below should work as you would expect:
```bash
$ less file.ext
$ less file.ext:23
$ less file.ext-24
$ less file.ext 23
$ less file.ext:23:	if [ ...
$ less file.ext-24-		local ...
```

If you like this then you may want to check out the `vi(m)` equivalent [vi-wrapper](https://github.com/bashmarklets/vi-wrapper).

## Example use case
```bash
[bash@marklet:~/]
$ grep -rn _LESS_WRAPPER_BIN bashmarklets                                                                                                                                   
bashmarklets/less-wrapper/less_wrapper.inc:7:	if [ ! -z "${_LESS_WRAPPER_BIN}" ]; then
bashmarklets/less-wrapper/less_wrapper.inc:8:		local LESS=${_LESS_WRAPPER_BIN}

[bash@marklet:~/]
$ less bashmarklets/less-wrapper/less_wrapper.inc:8:
```

## How to install

Either download/clone this repository and add the following to your `~/.bashrc` file:
```bash
source path/to/less_wrapper.inc
```

or alternatively just copy-paste the function directly into your `~/.bashrc` file.

NB: The source approach is recommended if you end up picking up more than one of these bookmarklets as it avoids clutter.

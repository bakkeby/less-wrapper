#!/bin/bash
# A 'grep -n' compatible less wrapper that lets you "less" (open)
# a file at a given line number.
# e.g. $ less file.ext:23

less () {
	if [ ! -z "${_LESS_WRAPPER_BIN}" ]; then
		local LESS=${_LESS_WRAPPER_BIN}
        elif [ -x /usr/bin/less ]; then
                local LESS=/usr/bin/less
	else
		local LESS=/bin/less
        fi
        
        # file.ext ?23?
        local filename=$1
        local line_num=$2

	if [ ! -f "$filename" ]; then
		# file.ext:23
		local filename=$(echo $1 | sed 's/:.*$//')
		local line_num=$(echo $1 | sed -r 's/^[^:]+:([0-9]+).*$/\1/')
	fi

	if [ ! -f "$filename" ]; then
		# file.ext-23
		filename=$(echo $1 | sed -r 's/\-[0-9]+(\-|$).*$//')
		line_num=$(echo $1 | sed -r 's/^.*\-([0-9]+)(\-|$).*$/\1/')
	fi
	
	if [[ $line_num =~ ^[0-9]+$ ]] && [ -f "$filename" ]; then
		$LESS +$line_num ${_LESS_WRAPPER_COMMANDS:-"-w -g -j 10"} $filename
	else
		$LESS $filename
	fi
}

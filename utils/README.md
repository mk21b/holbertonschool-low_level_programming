Quality of Life Tweaks

Installation:
Please run the below command inside the utils directory;
	qol 100

Provides an Alias for sandbox name, changes shell text colours, and allows for tracking of git changes.

Also provides access to the following aliases;
	gall - uploads all files in the current working directory to github.
	gcl - allows git clone to be used with syntax "gcl <user> <repo name>" - also includes shortcuts to clone my repos.
	gnew - creates a new directory and simple files, usage: "gnew <dir_name> <file_name*>" *file name may be omitted to skip creation.
	nq OR nextq - cleans up the working directory and lists contents
	pl - pushes the last modified file to github.

	qol - quality of life script usage: "qol <integer>"
		integer is a 3-bit, bitwise integer, in order, the bits toggle:
			- .bashrc update and source + script update
			- clones Sprint 1 repo
			- clones Printf repo

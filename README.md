# bbazelisk

This is a little multi-arch [bazelisk][0] launcher based on [csomopolitan libc][1].
The `bbazelisk` executable will exec the program `bazelisk-${sys}-${arch}`
out of the directory containing the executable.

You could imagine hypothetically putting this executable under `tools/bazel` in a monorepo,
and then putting installs of bazelisk next to it. Then just put a `.bazelversion` in your repo,
and anyone running `tools/bazel` on any platform will run the correct Bazel.

[0]: https://github.com/bazelbuild/bazelisk
[1]: https://justine.lol/ape.html

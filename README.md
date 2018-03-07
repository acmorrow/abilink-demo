This repository contains a toy project that demonstrates the build
system behavior mentioned in <LINK>.

The project contains two build systems, one written in SCons, and one
written in CMake, which can then generate build systems for make,
Ninja, etc.

The SCons build is configured so that you can build in three modes:

- Static, with `--link-model=static`
- Dynamic (the default), with `--link-model=dynamic`
- Dynamic with ABI driven linking, with `--link-model=dynamic-abi`

The `--link-model=dynamic-abi` option will only work if you have the
`abidw` tool from libabigail (not availble for Windows or OS X)
installed. If you have it in an unusual location, you can add
`ABIDW=/path/to/abidw` to your SCons invocation to specify where to
find it.

The CMake build uses the traditional `-DBUILD_SHARED_LIBS` technique
to decide whether or not to build shared libraries, and defaults to
building in dynamic mode.

There are three branches in the project:

- `master`, the baseline configuration
- `abi-preserving-change`, a mutation over baseline that does not alter the ABI
- `abi-altering-change`, a mutation over baseline that *does* alter the ABI.

You can use switching between these branches to follow along with the
blog post and observe the rebuild steps associated with the mutations
in the various build systems and build system modes.

In particular, it is interesting to compare and contrast the rebuild
work when using SCons in `--link-model=dynamic` mode when introducing
both ABI preserving and altering changes, with the rebuild work
associated with those same mutations in `--link-model=dynamic-abi`
mode.

If you are aware of other build systems which would exhibit
interesting behavior, pull requests to add them are welcome.

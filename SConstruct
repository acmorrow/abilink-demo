DefaultEnvironment(tools=[])

AddOption(
    '--link-model',
    dest='link-model',
    type='choice',
    choices=[
        'static',
        'dynamic',
        'dynamic-abi',
    ],
    default='dynamic'
)

AddOption(
    '--cache',
    dest='cache',
    nargs=0
)

# Setup the command-line variables
def variable_shlex_converter(val):
    # If the argument is something other than a string, propogate
    # it literally.
    if not isinstance(val, basestring):
        return val
    return shlex.split(val, posix=True)

env_vars = Variables()

env_vars.Add('BUILD_DIR',
    default='#/build'
)

env_vars.Add('CC')
env_vars.Add('CXX')
env_vars.Add('ABIDW')
env_vars.Add('CCFLAGS', converter=variable_shlex_converter)
env_vars.Add('CXXFLAGS', converter=variable_shlex_converter)
env_vars.Add('CPPPATH', converter=variable_shlex_converter)
env_vars.Add('LIBPATH', converter=variable_shlex_converter)
env_vars.Add('LINKFLAGS', converter=variable_shlex_converter)

env = Environment(
    variables=env_vars,
)

if not 'MSVC_VERSION' in env:
    env.AppendUnique(
        CXXFLAGS=[
            '-std=c++14',
        ],
        LINKFLAGS=[
            '$CXXFLAGS',
        ]
    )
    if not env['PLATFORM'] == 'darwin':
        env.AppendUnique(
            CCFLAGS=[
                '-pthread',
            ],
        )

link_model = GetOption('link-model')
if link_model == 'static':
    env['BUILDERS']['Library'] = env['BUILDERS']['StaticLibrary']
else:
    env['BUILDERS']['Library'] = env['BUILDERS']['SharedLibrary']
    if link_model == 'dynamic-abi':
        abilink = Tool('abilink')
        if not abilink.exists(env):
            print("Failed to enable abi driven linking; do you have the abidw tool available?")
            print("You can configure a path to it by adding ABIDW=/path/to/abidw to your SCons arguments")
            Exit(1)
        abilink(env)

env['VARIANT_DIR'] = env.subst('$BUILD_DIR/' + link_model)
sconsDir = env.Dir(env.subst('$BUILD_DIR/scons'))
env.SConsignFile(str(sconsDir.File('signatures')))
if GetOption('cache') is not None:
    env.CacheDir(str(sconsDir.Dir('cache')))

env.SConscript(
    dirs=[
        '.'
    ],
    variant_dir=env.subst('$VARIANT_DIR'),
    exports=[
        'env'
    ],
    duplicate=False,
)

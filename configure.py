# vim: set sts=2 ts=8 sw=2 tw=99 et:
import sys
import ambuild.runner as runner

# Simple extensions do not need to modify this file.

run = runner.Runner()

run.options.add_option('--mms-path', type=str, dest='mms_path', default=None,
                       help='Path to Metamod:Source')
run.options.add_option('--sm-path', type=str, dest='sm_path', default=None,
                       help='Path to SourceMod')
run.options.add_option('--enable-debug', action='store_const', const='1', dest='debug',
                       help='Enable debugging symbols')
run.options.add_option('--enable-optimize', action='store_const', const='1', dest='opt',
                       help='Enable optimization')

run.Configure(sys.path[0])

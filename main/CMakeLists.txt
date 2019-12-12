set(COMPONENT_SRCS "main.c"
                   "port/device.c"
				   "port/bo.c"
				   "port/bip_init.c"
				   "port/ai.c"
				   "src/dcc.c"
				   "src/apdu.c"
				   "src/address.c"
				   "src/bvlc.c"
				   "src/tsm.c"
				   "src/bacapp.c"
				   "src/bacdcode.c"
				   "src/bacstr.c"
				   "src/datetime.c"
				   "src/bacint.c"
				   "src/bip.c"
				   "src/debug.c"
				   "src/bacreal.c"
				   "src/lighting.c"
				   "src/bacaddr.c"
				   "src/bactext.c"
				   "src/indtext.c"
				   "src/npdu.c"
				   "src/iam.c"
				   "src/abort.c"
				   "src/reject.c"
				   "src/proplist.c"
				   
				   "src/rp.c"
				   "src/bacerror.c"
				   				   
				   
				   
				   
				   )

set(COMPONENT_ADD_INCLUDEDIRS "include" "port/include")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

register_component()

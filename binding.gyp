{
	"targets" : [
		{
			"target_name" : "433-utils",
			"dependencies" : [
				"deps/binding.gyp:433Utils"
			],
			"include_dirs": [
				"<!(node -e \"require('nan')\")"
			],
			"libraries": ["-lwiringPi"],
			"sources" : [
				"src/transmitter.cc",
				"src/receiver.cc",
				"src/433utils.cc"
			]
		}
	]
}

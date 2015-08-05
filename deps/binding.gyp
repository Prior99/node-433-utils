{
	"target_defaults" : {
		"default_configuration" : "Release",
		"configuration" : {
			"Release" : {
				"defines" : ["NODEBUG"]
			}
		}
	},
	"targets" : [
		{
			"target_name" : "433Utils",
			"type" : "static_library",
			"libraries": ["-lwiringPi"],
			"sources" : [
				"433Utils/RPi_utils/RCSwitch.cpp"
			]
		}
	]
}

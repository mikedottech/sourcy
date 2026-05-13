--[[
   Cloudi_master.lua
   Master file for Cloudi
   Generated on 2026-05-13.

   by Sourcy Code Translator
   (c) 2012 - radexx

  Runtime version: 1.0

]]

-- Class definition
Cloudi = BaseClass(FightActor)

-- Add some attributes definitions to be filled later on
Cloudi.m_constants = {}
Cloudi.m_commands = {}
Cloudi.m_buttonsRemap = {}

-- Set the path of this file
require("debug")
local dpath = debug.getinfo(1, "S").source
Cloudi.m_path = dpath:match"@(.+/).+%..+"

-- Basic information
Cloudi._type = "Cloudi"
Cloudi.runtimeVersion = "1.0"

-- List of scripts
Cloudi.m_scriptList = {
	"cloudi_cmd.lua",
	"cloudi.lua",
	"cloudcommon.lua",
}

-- Cloudi's constructor
function Cloudi:constructor()

	-- Other attributes
	self._class = Cloudi
end

-- First-time load of scripts
FightActor.reloadScripts(Cloudi)

return Cloudi



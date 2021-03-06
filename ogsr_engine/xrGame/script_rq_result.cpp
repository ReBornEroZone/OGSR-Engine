#include "stdafx.h"
#include "script_game_object.h"
#include "GameObject.h"
#include "..\xr_3da\xr_collide_defs.h"
#include "script_rq_result.h"

void script_rq_result::set_result(collide::rq_result _res)
{
	range		= _res.range;
	element		= _res.element;
	result		= true;
	if (_res.O)
	{
		CGameObject *obj = smart_cast<CGameObject *>(_res.O);
		if (obj)
			object = obj->lua_game_object();
	}
}
using namespace luabind;

#pragma optimize("s",on)
void script_rq_result::script_register(lua_State *L)
{
	module(L)
		[
			class_<script_rq_result>("rq_result")
				.def_readonly("range", &script_rq_result::range)
				.def_readonly("object", &script_rq_result::object)
				.def_readonly("element", &script_rq_result::element)
				.def_readonly("result", &script_rq_result::result)
		];
}
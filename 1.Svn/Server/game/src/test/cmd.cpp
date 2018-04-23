///Add
ACMD(do_item_check)
{
	ch->EditMyInven();
}

//Find
	{ "set",		do_set,			0,			POS_DEAD,	GM_IMPLEMENTOR	},

///Add
	{ "item_check",		do_item_check,		0,			POS_DEAD,	GM_PLAYER	},
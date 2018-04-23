//Find
static bool FN_check_item_socket(LPITEM item)
{

///Add(Coppied from cTolip)
	if (item->GetType() == ITEM_USE && item->GetSubType() == USE_AFFECT)
		return true;

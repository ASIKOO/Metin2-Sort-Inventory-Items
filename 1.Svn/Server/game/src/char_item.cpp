//Coppied from cTolip's Topic

//Find
static bool FN_check_item_socket(LPITEM item)
{

///Add
	if (item->GetType() == ITEM_USE && item->GetSubType() == USE_AFFECT)
		return true;

//Find in LPITEM CHARACTER::AutoGiveItem(DWORD dwItemVnum, BYTE bCount, int iRarePct, bool bMsg)
	if (item->GetVnum() == dwItemVnum && FN_check_item_socket(item))
///Change
	if (item->GetOriginalVnum() == dwItemVnum && FN_check_item_socket(item))

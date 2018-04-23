///Add
static bool SortMyItems(const LPITEM & s1, const LPITEM & s2) 
{ 
	/// change what you want
	std::string name(s1->GetName());
	std::string name2(s2->GetName());
	return name < name2;
	// return s1->GetVnum() < s2->GetVnum();
}
void CHARACTER::EditMyInven()
{
	if (IsDead())
		return;
	static std::vector<LPITEM> v;
    LPITEM myitems;
	
	///clear vector
	v.clear();
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	int size = Inventory_Size();
#else
	int size = INVENTORY_MAX_NUM;
#endif

	for (int i = 0; i < size; ++i)
	{
		if (!(myitems = GetInventoryItem(i))) 
			continue;
		
		///add all items inven to vector
		v.push_back(myitems);
		
		///delete items from inven
		myitems->RemoveFromCharacter();
	}
	///Sort items
	std::sort(v.begin(), v.end(), SortMyItems);
	
	///Send vector items to inven
	itertype(v) it = v.begin();
	while (it != v.end()) {	
		LPITEM item = *(it++);
		if (item) {
			TItemTable * p = ITEM_MANAGER::instance().GetTable(item->GetVnum());
			/// isn't same function !
			if (p && p->dwFlags & ITEM_FLAG_STACKABLE && p->bType != ITEM_BLEND)
				AutoGiveItem(item->GetVnum(), item->GetCount()); // create new item for stackable items
			else
				AutoGiveItem(item); // copy orginal items
		}
	}
	
	///message
	ChatPacket(CHAT_TYPE_INFO, "Your items sorted.");
}

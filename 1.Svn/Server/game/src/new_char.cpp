//For C++11(+)

#ifdef ENABLE_SORT_INVEN
void CHARACTER::EditMyInven()
{
	if (IsDead()) return;
	static std::vector<LPITEM> v;
  LPITEM myitems;
	
	v.clear();
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	auto size = Inventory_Size();
#else
	auto size = INVENTORY_MAX_NUM;
#endif

	for (auto i = 0; i < size; size++)
	{
		 if (!(myitems = GetInventoryItem(i))) 
			 continue;
       
	  v.push_back(myitems);	
	  myitems->RemoveFromCharacter();
	}
  std::sort(v.begin(), v.end(), [] (const LPITEM & a, const LPITEM & b) -> 
	bool
	{ 
	  std::string name(a->GetName());
		std::string name2(b->GetName());
		return name < name2;
		// return s1->GetVnum() < s2->GetVnum();
	});
	
	auto it = v.begin();
	while (it != v.end()) {	
		auto item = *(it++);
		if (item) {
			TItemTable * p = ITEM_MANAGER::instance().GetTable(item->GetVnum());
			if (p && p->dwFlags & ITEM_FLAG_STACKABLE && p->bType != ITEM_BLEND)
				AutoGiveItem(item->GetVnum(), item->GetCount(), -1, false);
			else
				AutoGiveItem(item);
		}
	}
  
	ChatPacket(CHAT_TYPE_INFO, "Your items sorted.");
}
#endif

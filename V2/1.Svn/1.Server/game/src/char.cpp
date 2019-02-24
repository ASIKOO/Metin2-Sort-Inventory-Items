///Add
#ifdef ENABLE_SORT_INVEN
void CHARACTER::SortInven(BYTE option)
{
	if (IsDead()) return;
	std::vector<LPITEM> all;
    LPITEM myitems;
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	auto size = Inventory_Size();
#else
	auto size = INVENTORY_MAX_NUM;
#endif

	for (auto i = 0; i < size; ++i) {
		if (myitems = GetInventoryItem(i)) {
			all.emplace_back(myitems);
			myitems->RemoveFromCharacter();
		}
	}
	std::sort(all.begin(), all.end(), [option](auto i1, auto i2) {
		switch (option) {
			case 2:
				return i1->CustomSort() == i2->CustomSort() ? i1->GetSubType() < i2->GetSubType() : i1->CustomSort() < i2->CustomSort();
			break;
			case 3:
				return i1->GetLevelLimit() == i2->GetLevelLimit() ? i1->GetSubType() < i2->GetSubType() : i1->GetLevelLimit() > i2->GetLevelLimit();
			break;
			default:
				return std::strcmp(i1->GetName(),i2->GetName()) < 0;
			break;
		}
	});
	for (auto getitem : all) {
		auto table = ITEM_MANAGER::instance().GetTable(getitem->GetVnum());
		if (table && table->dwFlags & ITEM_FLAG_STACKABLE && table->bType != ITEM_BLEND)
			AutoGiveItem(getitem->GetVnum(), getitem->GetCount(), -1, false);
		else
			AutoGiveItem(getitem);
    };
}
#endif

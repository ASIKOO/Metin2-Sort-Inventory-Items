//Find
		BYTE		GetAttributeType(int i)	{ return m_aAttr[i].bType;	}
		
///Add
#ifdef ENABLE_SORT_INVEN
		BYTE CustomSort()	{ 
			// You can change and use Getvnum etc.
			switch(m_pProto->bType) {
				case ITEM_WEAPON:
					return 1;
				break;
				case ITEM_ARMOR:
					return 2;
				break;
				case ITEM_USE:
					return 3;
				break;
				case ITEM_BELT:
					return 4;
				break;
				case ITEM_COSTUME:
					return 5;
				break;
				case ITEM_SKILLBOOK:
				case ITEM_SKILLFORGET:
					return 6;
				break;
				default:
					return 7;
				break;
			}
		}
#endif
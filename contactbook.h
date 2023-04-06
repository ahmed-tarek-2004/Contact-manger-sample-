#ifndef contactbook_h
#define contactbook_h
#include "contact.h"
class contactbook
{
	int contact_count;
	int contact_size;
	//int deleted_counter;
	contact* my_contacts;
public:
	contactbook(int m_size);
	void Find();
	void Edit();
	void Delete();
	void show();
	void add();
	bool research_names(string sign);
	bool research_city(string sign);
	bool research_phone(string sign);
	~contactbook();
};
#endif

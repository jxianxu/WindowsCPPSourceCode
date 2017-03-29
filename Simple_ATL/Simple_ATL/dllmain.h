// dllmain.h : Declaration of module class.

class CSimple_ATLModule : public ATL::CAtlDllModuleT< CSimple_ATLModule >
{
public :
	DECLARE_LIBID(LIBID_Simple_ATLLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SIMPLE_ATL, "{85551E10-3600-4F03-9291-4B03D4B7E3F9}")
};

extern class CSimple_ATLModule _AtlModule;

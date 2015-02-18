#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Main)


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Main"); }

		static ::String go;
		static ::String go_s;
		static ::String set;
		static ::String set_s;
		static ::String explore;
		static ::String explore_s;
		static ::String list;
		static ::String list_s;
		static ::String run;
		static ::String run_s;
		static Dynamic props;
		static Void main( );
		static Dynamic main_dyn();

		static ::String getFilePath( );
		static Dynamic getFilePath_dyn();

};


#endif /* INCLUDED_Main */ 

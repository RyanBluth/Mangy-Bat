#ifndef INCLUDED_haxe_io_Path
#define INCLUDED_haxe_io_Path

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Path)
namespace haxe{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  Path_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Path_obj OBJ_;
		Path_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Path_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Path_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Path"); }

		static ::String removeTrailingSlashes( ::String path);
		static Dynamic removeTrailingSlashes_dyn();

};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_Path */ 

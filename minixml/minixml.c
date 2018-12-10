// minixml.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <stdio.h>
#include "mxml.h"
#include "minixml.h"

int GetVendorInfo(const char* xmlpath,Vendor_t* VendorInfo)
{
	mxml_node_t *tree,*Vendor,*Id,*Name,*Imagedata;
	FILE* fp = fopen(xmlpath, "r");
	if (!fp)
	{
		Nex_PRINT("Can't Open The XML File\n");
		return 0;
	}
	tree = mxmlLoadFile(NULL, fp, MXML_OPAQUE_CALLBACK);
	fclose(fp);
	if (!tree)
	{
		Nex_PRINT("XML LoadFile failed\n");
		return 0;
	}
	Nex_PRINT("Below is a description of Vendor:\n");
	Vendor = mxmlFindElement(tree, tree, "Vendor", NULL, NULL, MXML_DESCEND);
	VendorInfo->FileVersion = mxmlElementGetAttr(Vendor, "FileVersion");
	Nex_PRINT("FileVersion = %s\n", VendorInfo->FileVersion);
	Id = mxmlFindElement(Vendor, tree, "Id", NULL, NULL, MXML_DESCEND);
	VendorInfo->Id = Id->child->value.element.name;
	Nex_PRINT("Id = %s\n", VendorInfo->Id);
	Name = mxmlFindElement(Vendor, tree, "Name", NULL, NULL, MXML_DESCEND);
	VendorInfo->Name = Name->child->value.element.name;
	Nex_PRINT("Name = %s\n", VendorInfo->Name);
	Imagedata = mxmlFindElement(Vendor, tree, "ImageData16x14", NULL, NULL, MXML_DESCEND);
	VendorInfo->ImageData = Imagedata->child->value.element.name;
	Nex_PRINT("Imagedata = %s\n", VendorInfo->ImageData);
	mxmlDelete(tree);
	return 1;
}

int GetGroupInfo(const char* xmlpath, group_t* group)
{
	mxml_node_t *Groups, *tree, *Type, *Name, *Imagedata;
	FILE* fp = fopen(xmlpath, "r");
	if (!fp)
	{
		Nex_PRINT("Can't Open The XML File\n");
		return 0;
	}
	tree = mxmlLoadFile(NULL, fp, MXML_OPAQUE_CALLBACK);
	fclose(fp);
	if (!tree)
	{
		Nex_PRINT("XML LoadFile failed\n");
		return 0;
	}
	Nex_PRINT("Below is a description of Group:\n");
	Groups = mxmlFindElement(tree, tree, "Descriptions", NULL, NULL, MXML_DESCEND);
	Groups = mxmlFindElement(Groups, tree, "Groups", NULL, NULL, MXML_DESCEND);
	Groups = mxmlFindElement(Groups, tree, "Group", NULL, NULL, MXML_DESCEND);
	Type = mxmlFindElement(Groups, tree, "Type", NULL, NULL, MXML_DESCEND);
	group->Type = Type->child->value.element.name;
	Nex_PRINT("Type = %s\n", group->Type);
	Name = mxmlFindElement(Groups, tree, "Name", NULL, NULL, MXML_DESCEND);
	group->Name = Name->child->value.element.name;
	Nex_PRINT("Name = %s\n", group->Name);
	Imagedata = mxmlFindElement(Groups, tree, "ImageData16x14", NULL, NULL, MXML_DESCEND);
	group->ImageData = Imagedata->child->value.element.name;
	Nex_PRINT("Imagedata = %s\n", group->ImageData);
	mxmlDelete(tree);
	return 1;

}


int main()
{
	Vendor_t vendor;
	group_t group;
	GetVendorInfo("DM3E_V1.70_Example.xml", &vendor);
	GetGroupInfo("DM3E_V1.70_Example.xml", &group);
	return 0;
}


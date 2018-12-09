// minixml.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mxml.h"


int main()
{
	FILE* fp;
	mxml_node_t* tree,*node;
	fp = fopen("DM3E_V1.70_Example.xml","r");
	tree = mxmlLoadFile(NULL, fp, MXML_OPAQUE_CALLBACK);
	fclose(fp);

	mxml_node_t* val,*id,*group,*Type,*Name,*Imagedata;
	node = mxmlFindElement(tree,tree,"EtherCATInfo",NULL,NULL,MXML_DESCEND);
	printf("%s\n", mxmlElementGetAttr(node, "Version"));
	printf("%s\n", mxmlElementGetAttr(node, "xsi:noNamespaceSchemaLocation"));
	printf("%s\n", mxmlElementGetAttr(node, "xmlns:xsi"));

	val = mxmlFindElement(node, tree, "Vendor", NULL, NULL, MXML_DESCEND);
	printf("%s\n", mxmlElementGetAttr(val, "FileVersion"));

	id = mxmlFindElement(val, tree, "Id", NULL, NULL, MXML_DESCEND);
	printf("%s\n", id->child->value.element.name);
	id = mxmlFindElement(val, tree, "Name", NULL, NULL, MXML_DESCEND);
	printf("%s\n", id->child->value.element.name);
	id = mxmlFindElement(val, tree, "ImageData16x14", NULL, NULL, MXML_DESCEND);
	printf("%s\n", id->child->value.element.name);

	group = mxmlFindElement(tree, tree, "Descriptions", NULL, NULL, MXML_DESCEND);
	group = mxmlFindElement(group, tree, "Groups", NULL, NULL, MXML_DESCEND);
	group = mxmlFindElement(group, tree, "Group", NULL, NULL, MXML_DESCEND);
	Type = mxmlFindElement(group, tree, "Type", NULL, NULL, MXML_DESCEND);
	printf("%s\n", Type->child->value.element.name);

	Name = mxmlFindElement(group, tree, "Name", NULL, NULL, MXML_DESCEND);
	printf("%s\n", mxmlElementGetAttr(Name, "LcId"));
	printf("%s\n", Name->child->value.element.name);

	Imagedata = mxmlFindElement(group, tree, "ImageData16x14", NULL, NULL, MXML_DESCEND);
	printf("%s\n", Imagedata->child->value.element.name);
}


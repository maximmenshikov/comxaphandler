/*
	Header: ComXapApi.h
	Project: COMXapHandler
	Author: ultrashot
	Comment: Public definitions for Application API. 
	
	Please, note that not a single part of Com Xap API
	code or its static library could be used without author's permission
*/
#pragma once
#ifndef COMXAPAPI
#define COMXAPAPI

typedef enum
{
	ProductID = 0,
	InstanceID = 1,
	OfferID = 2
}GuidIndex;

typedef enum
{
	AppId = 0,
	IsNotified = 1,
	AppInstallType = 2,
	AppState = 3,
	IsRevoked = 4,
	IsUpdateAvailable = 5,
	IsUninstallable = 6,
	IsThemable = 7,
	Rating = 8,
	AppId2 = 9,
	Genre = 10
}AppInfoIntegerIndex;

typedef enum 
{
	DefaultTask = 0,
	Title = 1,
	ApplicationIcon = 2,
	InstallFolder = 3,
	DataFolder = 4,
	Publisher = 6,
	Author = 7,
	Description = 8,
	Version = 9,
	ImagePath = 10
}AppInfoStringIndex;

#endif
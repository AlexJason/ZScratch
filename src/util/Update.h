#pragma once
#ifndef ZSCRATCH_UTIL_UPDATE
#define ZSCRATCH_UTIL_UPDATE

#include <string>
#include <vector>

enum class UpdateType {
	NonMandatory,
	Mandatory
};

enum class UpdateKey {
	BUILD_ALPHA,
	BUILD_BETA,
	BUILD_PREVIEW,
	RELEASE_STANDARD_REVISION,
	RELEASE_STANDARD_MINOR,
	RELEASE_STANDARD_MAJOR,
	NEVER_UPDATE
};

#endif

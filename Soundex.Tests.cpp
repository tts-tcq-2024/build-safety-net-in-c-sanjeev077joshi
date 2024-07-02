#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  char soundex[5];
 
  generateSoundex("AX", soundex);
  ASSERT_EQ(soundex,"A200");

 generateSoundex("Smith", soundex);
 ASSERT_EQ(soundex,"S530");
}

TEST(SoudexTestsuite, ShortNameTest) {

  char soundex[5];

  generateSoundex("A", soundex);
  ASSERT_EQ(soundex,"A000");
}

TEST(SoudexTestsuite, casesensitivelowercase)
{
	  char soundex[5];

	  generateSoundex("johnson", soundex);
	  ASSERT_EQ(soundex,"J525");
}

TEST(SoudexTestsuite, specialcharacters)
{
	  char soundex[5];

	  generateSoundex("%jkl", soundex);
	  ASSERT_EQ(soundex,"%240");
}

TEST(SoudexTestsuite, longname)
{
	  char soundex[5];

	  generateSoundex("Rameshkumar", soundex);
	  ASSERT_EQ("R525", soundex);
}

#include "NGO.h"


NGO::NGO(string inLine) {
	vector<string> row;
	stringstream rowString(inLine);
	string word;

	while (getline(rowString, word, ','))
	{
		row.push_back(word);
	}
	EIN = stoi(row[0]);
	name = row[1];
	state = row[5];
	zip = row[6];
	incomeCode = stoi(row[15]);
	address = row[3] + ", " + row[4] + ", " + row[5] + ", " + row[6];
	if (incomeCode != 0 && row[25] != "") {
		income = stoll(row[24], nullptr, 10);
	}
	else
		income = 0;

}

NGO::NGO(string name_, string zip_, long int income_) {
	name = name_;
	zip = zip_;
	income = income_;
}

NGO::NGO() {
	name = "";
	zip = "";
	income = 0;
}

void NGO::printName() {
	cout << name << ", ";
}

string NGO::getZip() {
	return zip;
}

unsigned long int NGO::getIncome() {
	return income;
}

string NGO::getName() {
	return name;
}

string NGO::getAddress() {
	return address;
}

string NGO::getState() {
	return state;
}

vector<string> NGO::getType() {
	return types;
}
/*
string NGO::setType(string code){
	
	if (code == "001")
		return "Religious";
	else if (code == "002")
		return "Religious";
	else if (code == "")
		return "Religious";
	else if (code == "003")
		return "Religious";
	else if (code == "004")
		return "Religious";
	else if (code == "005")
		return "Religious";
	else if (code == "006")
		return "Religious";

	else if (code == "007")
		return "Religious";

	else if (code == "008")
		return "Religious";

	else if (code == "029")
		return "Religious";

	else if (code == "030")
		return "Education";
	else if (code == "031")
		return "Education";
	else if (code == "032")
		return "Education";
	else if (code == "033")
		return "Education";
	else if (code == "034")
		return "Education";
	else if (code == "035")
		return "Education";
	else if (code == "036")
		return "Education";
	else if (code == "037")
		return "Education";
	else if (code == "038")
		return "Education";
	else if (code == "039")
		return "Education";
	else if (code == "040")
		return "Education";
	else if (code == "041")
		return "Education";
	else if (code == "042")
		return "Education";
	else if (code == "043")
		return "Education";
	else if (code == "044")
		return "Education";
	else if (code == "045")
		return "Education";
	else if (code == "046")
		return "Education";
	else if (code == "059")
		return "Education";
	else if (code == "060")
		return "Cultural or Historical";
	else if (code == "061")
		return "Cultural or Historical";
	else if (code == "062")
		return "Cultural or Historical";
	else if (code == "063")
		return "Cultural or Historical";
	else if (code == "064")
		return "Cultural or Historical";
	else if (code == "065")
		return "Cultural or Historical";
	else if (code == "088")
		return "Cultural or Historical";
	else if (code == "089")
		return "Cultural or Historical";
	else if (code == "090")
		return "Cultural or Historical";
	else if (code == "091")
		return "Cultural or Historical";
	else if (code == "092")
		return "Cultural or Historical";
	else if (code == "093")
		return "Cultural or Historical";
	else if (code == "094")
		return "Cultural or Historical";
	else if (code == "119")
		return "Cultural or Historical";
	else if (code == "120")
		return "Instructional or Informational";
	else if (code == "121")
		return "Instructional or Informational";
	else if (code == "122")
		return "Instructional or Informational";
	else if (code == "123")
		return "Instructional or Informational";
	else if (code == "124")
		return "Instructional or Informational";
	else if (code == "125")
		return "Instructional or Informational";
	else if (code == "126")
		return "Instructional or Informational";
	else if (code == "149")
		return "Instructional or Informational";

	else if (code == "150")
		return "Health Services";
	else if (code == "151")
		return "Health Services";
	else if (code == "152")
		return "Health Services";
	else if (code == "153")
		return "Health Services";
	else if (code == "154")
		return "Health Services";
	else if (code == "155")
		return "Health Services";
	else if (code == "156")
		return "Health Services";
	else if (code == "157")
		return "Health Services";
	else if (code == "158")
		return "Health Services";
	else if (code == "159")
		return "Health Services";
	else if (code == "160")
		return "Health Services";
	else if (code == "161")
		return "Health Services";
	else if (code == "162")
		return "Health Services";
	else if (code == "163")
		return "Health Services";
	else if (code == "164")
		return "Health Services";
	else if (code == "165")
		return "Health Services";
	else if (code == "166")
		return "Health Services";
	else if (code == "167")
		return "Health Services";
	else if (code == "168")
		return "Health Services";
	else if (code == "169")
		return "Health Services";
	else if (code == "179")
		return "Health Services";
	else if (code == "180")
		return "Scientific Research";
	else if (code == "181")
		return "Scientific Research";
	else if (code == "199")
		return "Scientific Research";
	else if (code == "200")
		return "Business or Professional";
	else if (code == "201")
	return "Business or Professional";
	else if (code == "202")
	return "Business or Professional";	
	else if (code == "202")
	return "Business or Professional";	
	else if (code == "203")
	return "Business or Professional";
	else if (code == "204")
	return "Business or Professional";
	else if (code == "205")
	return "Business or Professional";
	else if (code == "206")
	return "Business or Professional";
	else if (code == "207")
	return "Business or Professional";
	else if (code == "208")
	return "Business or Professional";
	else if (code == "209")
	return "Business or Professional";
	else if (code == "210")
	return "Business or Professional";
	else if (code == "211")
	return "Business or Professional";
	else if (code == "212")
	return "Business or Professional";
	else if (code == "213")
	return "Business or Professional";
	else if (code == "229")
	return "Business or Professional";
	else if (code == "230")
	return "Farming";
	else if (code == "231")
	return "Farming";
	else if (code == "232")
	return "Farming";
	else if (code == "233")
	return "Farming";
	else if (code == "234")
	return "Farming";
	else if (code == "235")
	return "Farming";
	else if (code == "236")
	return "Farming";
	else if (code == "237")
	return "Farming";
	else if (code == "249")
	return "Farming";
	else if (code == "250")
	return "Mutual Organization";	
	else if (code == "251")
	return "Mutual Organization";
	else if (code == "252")
	return "Mutual Organization";
	else if (code == "253")
	return "Mutual Organization";
	else if (code == "254")
	return "Mutual Organization";
	else if (code == "259")
	return "Mutual Organization";
	else if (code == "260")
	return "Membership Organizaton";
	else if (code == "261")
	return "Membership Organizaton";
	else if (code == "262")
	return "Membership Organizaton";
	else if (code == "263")
	return "Membership Organizaton";
	else if (code == "264")
	return "Membership Organizaton";
	else if (code == "265")
	return "Membership Organizaton";
	else if (code == "266")
	return "Membership Organizaton";
	else if (code == "267")
	return "Membership Organizaton";
	else if (code == "268")
	return "Membership Organizaton";
	else if (code == "269")
	return "Membership Organizaton";
	else if (code == "279")
	return "Membership Organizaton";
	else if (code == "280")
	return "Sports and Recreation";
	else if (code == "281")
	return "Sports and Recreation";
	else if (code == "282")
	return "Sports and Recreation";
	else if (code == "283")
	return "Sports and Recreation";
	else if (code == "284")
	return "Sports and Recreation";
	else if (code == "285")
	return "Sports and Recreation";
	else if (code == "286")
	return "Sports and Recreation";
	else if (code == "287")
	return "Sports and Recreation";
	else if (code == "288")
	return "Sports and Recreation";
	else if (code == "296")
	return "Sports and Recreation";
	else if (code == "297")
	return "Sports and Recreation";
	else if (code == "298")
	return "Sports and Recreation";
	else if (code == "299")
	return "Sports and Recreation";
	else if (code == "300")
	return "Sports and Recreation";
	else if (code == "301")
	return "Sports and Recreation";
	else if (code == "317")
	return "Sports and Recreation";
	else if (code == "318")
	return "Sports and Recreation";
	else if (code == "319")
	return "Sports and Recreation";

	else if (code == "320")
	return "Youth Activities";
	else if (code == "321")
	return "Youth Activities";
	else if (code == "322")
	return "Youth Activities";
	else if (code == "323")
	return "Youth Activities";
	else if (code == "324")
	return "Youth Activities";
	else if (code == "325")
	return "Youth Activities";
	else if (code == "326")
	return "Youth Activities";
	else if (code == "327")
	return "Youth Activities";
	else if (code == "328")
	return "Youth Activities";
	else if (code == "349")
	return "Youth Activities";
	else if (code == "350")
	return "Environmental and Conservation";
	else if (code == "351")
	return "Environmental and Conservation";
	else if (code == "352")
	return "Environmental and Conservation";
	else if (code == "353")
	return "Environmental and Conservation";
	else if (code == "354")
	return "Environmental and Conservation";
	else if (code == "355")
	return "Environmental and Conservation";
	else if (code == "356")
	return "Environmental and Conservation";
	else if (code == "379")
	return "Environmental and Conservation";
	else if (code == "380")
	return "Housing";
	else if (code == "381")
	return "Housing";
	else if (code == "382")
	return "Housing";
	else if (code == "398")
	return "Housing";
	else if (code == "399")
	return "Housing";
	else if (code == "400")
	return "Inner City and Community";
	else if (code == "401")
	return "Inner City and Community";
	else if (code == "402")
	return "Inner City and Community";
	else if (code == "403")
	return "Inner City and Community";
	else if (code == "404")
	return "Inner City and Community";
	else if (code == "405")
	return "Inner City and Community";
	else if (code == "406")
	return "Inner City and Community";
	else if (code == "407")
	return "Inner City and Community";
	else if (code == "408")
	return "Inner City and Community";
	else if (code == "429")
	return "Inner City and Community";
	else if (code == "430")
	return "Civil Rights";
	else if (code == "431")
	return "Civil Rights";
	else if (code == "432")
	return "Civil Rights";
	else if (code == "449")
	return "Civil Rights";
	else if (code == "460")
	return "Litigation and Legal Aid";
	else if (code == "461")
	return "Litigation and Legal Aid";
	else if (code == "462")
	return "Litigation and Legal Aid";
	else if (code == "463")
	return "Litigation and Legal Aid";
	else if (code == "465")
	return "Litigation and Legal Aid";
	else if (code == "480" || code == "481" || code == "482" || code == "482" || code == "484" || code == "509")
	return "Legislation and Political Activities";
	else if (code == "510" || code == "511" || code == "512" || code == "513" || code == "514" || code == "515" || 
	code == "516" || code == "517" || code == "518" || code == "519" || code == "520" || code == "521" || code == "522" 
	|| code == "523" || code == "524" || code == "525" || code == "526" || code == "527" || code == "528" || code == "529"
	|| code == "530" || code == "531" || code == "532" || code == "533" || code == "534" || code == "535" || code == "536" 
	|| code == "537" || code == "538" || code == "539" || code == "540" || code == "541" || code == "542" || code == "569")
	return "Advocacy";
	else if (code == "560" || code == "561" || code == "562" || code == "563" || code == "564" || code == "565" || code == "566" || code == "567" || code == "568" || code == "569"
	|| code == "572" || code == "573" || code == "574" || code == "575")
	return "Other Individual Activities";
	else if (code == "600" || code == "601" || code == "602" || code == "603")
	return "Activity Group";
	else if (code == "900" || code == "901" || code == "902" || code == "903" || code == "904" || code == "905" || code == "906" || code == "907" || code == "908" || code == "909" 
	|| code == "910" || code == "911" || code == "912" || code == "913" || code == "914" || code == "915" || code == "916" || code == "917" || code == "918" || code == "919"
	|| code == "920" || code == "921" || code == "922" || code == "923" || code == "924" || code == "925" || code == "926" || code == "927" || code == "928" || code == "930"
	|| code == "931" || code == "990" || code == "994" || code == "995" || code == "998")
	return "Other";
	else
	{
	return "";
	}







}
*/
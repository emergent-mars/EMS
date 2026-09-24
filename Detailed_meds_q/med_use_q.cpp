#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// randomizer
std::vector<int> random(int n){
  // obtain random seed from hardware
  std::random_device rd;
  // initialize standard engine with seed
  std::mt19937 gen(rd());
  // create question pool, questions #1-n
  std::vector<int> pool;
  for(int i=0; i<n; i++){pool.push_back(i);}
  
  // shuffle pool
  std::shuffle(pool.begin(), pool.end(), gen);

  return pool;
}

string tolowercase(string a){
  for(char &c : a){
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  }
  return a;
}


// questions
void check_answer(std::vector<string> answer){
  // initialize
  std::string user_answer;
  bool correct = true;
  std::size_t key;
  std::string user_answer_l;
  std::string answer_l;
  
  std::getline(std::cin, user_answer); // user input

  for(string s : answer){
   user_answer_l =  tolowercase(user_answer);
   answer_l =  tolowercase(s);
   key = user_answer_l.find(answer_l);
    if (key == std::string::npos){correct = false; break;}
  }
  if(correct){
    std::cout << "Correct!\n";
  } else if(!correct) {
    std::cout << "Incorrect :(\nCorrect answer was: ";
    for(std::string value : answer){std::cout << value << " ";}
    std::cout << "\n";
  }
  user_answer.clear();
}

void indications(vector<string> answer){
  std::cout << "What are the indications for this drug? ";
  check_answer(answer);
}
void contraindications(vector<string> answer){
  std::cout << "What are the contraindications for this drug? ";
  check_answer(answer);
}
void dosages(vector<string> answer, bool peds, std::vector<string> adult, std::vector<string> child, int max, vector<string> max_dose){
  bool p;
  bool mx;
  bool mx_a;
  std::string a;
  std::string aLC;
  int u_mx;
  
  std::cout << "Y/N: Are there different doses for adults vs children? ";
  std::cin >> a;
  aLC = tolowercase(a);
  std::cout << aLC << "\n";;
  if(aLC == "n"){p = false;} else if(aLC == "y"){p = true;}
  if(p == peds){std::cout << "Correct!\n";} else{std::cout << "Incorrect :(\n";}
  std::cin.ignore();
  
  if(peds){
    std::cout << "What is the adult dose and route for this drug? ";
    check_answer(adult);
    std::cout << "What is the pediatric dose? ";
    check_answer(child);
  } else{
    std::cout << "What is the dose and route for this drug? ";
    check_answer(answer);
  }

  if(max > 1){mx_a = true;}else if(max <= 1){mx_a = false;}
  std::cout << "Y-N-X: Can you administer this drug multiple times? ";
  std::cin >> a;
  aLC = tolowercase(a);
  std::cout << aLC << "\n";;
  if(aLC == "n" || aLC == "x"){mx = false;} else if(aLC == "y"){mx = true;}
  if(mx == mx_a){std::cout << "Correct!\n";} else{std::cout << "Incorrect :(\n";}

  if(mx_a==true){
    std::cout << "How many times can you administer the drug? ";
    std::cin >> u_mx;
    if(u_mx == max){std::cout << "Correct!\n";} else{std::cout << "Incorrect :(\nCorrect answer was " << max << "\n";}
    std::cin.ignore();
    std::cout << "What is the maximum dose? ";
    check_answer(max_dose);
  }
  std::cin.ignore();
}


int main(){
  // main function
  std::vector<int> pool = random(11);
 
  bool peds;
  bool multi;
  int max;

  std::cout << "Correct answer will print keywords only.\nIf the drug can be given multiple times, for some reason it requiers you hit enter a second time before it moves on. I dunno why this is happening but trying to fix it is a pain in the ass so I won't.\n";
  // drugs case/switch

  for(int drug : pool){
    switch(drug){
    case 1: {std:cout << "Aspirin\n";
      std::vector<string> asp_indications = {"cardiac", "chest", "pain" };
      indications(asp_indications);
      std::vector<string> asp_contraindications = {"GI", "bleed", "allergy", "16"};
      contraindications(asp_contraindications);
      std::vector<string> asp_doses = {"324", "mg", "PO" };
      peds = false;
      std::vector<string> asp_adult = {"null"};
      std::vector<string> asp_child = {"null"};
      max = 0;
      std::vector<string> asp_max_dose = {"null"};
      dosages(asp_doses, peds, asp_adult, asp_child, max, asp_max_dose);
      std::cout << "\n";
      break;}
    case 2: {std::cout << "Albuterol\n";
	std::vector<string> alb_indications = {"respiratory", "distress", "bronchial asthma", "COPD"};
	indications(alb_indications);
	std::vector<string> alb_contraindications = {"severe", "tachycardia"};
	contraindications(alb_contraindications);
	std::vector<string> alb_doses = {"SVN", "6-8 LPM", "O2", "2.5 mg", "3 ml", "saline", "2 puffs"};
	peds = false;
	std::vector<string> alb_adult = {"null"};
	std::vector<string> alb_child = {"null"};
	max = 0;
	std::vector<string> alb_max_dose = {"null"};
	dosages(alb_doses, peds, alb_adult, alb_child, max, alb_max_dose);
	std::cout << "\n";
	break;}
    case 3: {std::cout << "Epinephrine\n";
	std::vector<string> epi_indications = {"anaphylactic", "respiratory", "distress"};
	indications(epi_indications);
	std::vector<string> epi_contraindications = {"none", "life-threatening"};
	contraindications(epi_contraindications);
	std::vector<string> epi_doses = {"null"};
	peds = true;
	std::vector<string> epi_adult = {"0.3", "mg", "IM"};
	std::vector<string> epi_child = {"0.15", "mg"};
	max = 0;
	std::vector<string> epi_max_dose = {"null"};
	dosages(epi_doses, peds, epi_adult, epi_child, max, epi_max_dose);
	std::cout << "\n";
	break;}
    case 4: {std::cout << "Nalaxone\n";
	std::vector<string> nal_indications = {"opioid", "CNS", "respiratory", "depression", "overdose"};
	indications(nal_indications);
	std::vector<string> nal_contraindications = {"none"};
	contraindications(nal_contraindications);
	std::vector<string> nal_doses = {"0.5", "mg", "IV", "IN"};
	peds = false;
	std::vector<string> nal_adult = {"null"};
	std::vector<string> nal_child = {"null"};
	max = 4;
	std::vector<string> nal_max_dose = {"2", "mg"};
	dosages(nal_doses, peds, nal_adult, nal_child, max, nal_max_dose);
	std::cout << "\n";
	break;}
    case 5: {std::cout << "Nitroglycerin\n";
	std::vector<string> nit_indications = {"cardiac", "chest", "pain"};
	indications(nit_indications);
	std::vector<string> nit_contraindications = {"systolic", "below 100 mmHg", "ED", "24 hours", "BP drop", "30 mmHg"};
	contraindications(nit_contraindications);
	std::vector<string> nit_doses = {"0.4", "mg", "tablet", "spray", "sublingual"};
	peds = false;
	std::vector<string> nit_adult = {"null"};
	std::vector<string> nit_child = {"null"};
	max = 3;
	std::vector<string> nit_max_dose = {"1.2", "mg"};
	dosages(nit_doses, peds, nit_adult, nit_child, max, nit_max_dose);
	std::cout << "\n";
	break;}
    case 6: {std::cout << "Oral Glucose\n";
	std::vector<string> glu_indications = {"hypoglycemia"};
	indications(glu_indications);
	std::vector<string> glu_contraindications = {"unable", "swallow"};
	contraindications(glu_contraindications);
	std::vector<string> glu_doses = {"15", "g", "buccally"};
	peds = false;
	std::vector<string> glu_adult = {"null"};
	std::vector<string> glu_child = {"null"};
	max = 0;
	std::vector<string> glu_max_dose = {"null"};
	dosages(glu_doses, peds, glu_adult, glu_child, max, glu_max_dose);
	std::cout << "\n";
	break;}
    case 7: {std::cout << "Acetaminophen\n";
	std::vector<string> ace_indications = {"mild", "moderate", "severe", "pain", "fever"};
	indications(ace_indications);
	std::vector<string> ace_contraindications = {"allergy", "chronic liver disease", "3", "g", "last 24 hours"};
	contraindications(ace_contraindications);
	std::vector<string> ace_doses = {"null"};
	peds = true;
	std::vector<string> ace_adult = {"1000", "mg", "PO"};
	std::vector<string> ace_child = {"15", "mg/kg"};
	max = 0;
	std::vector<string> ace_max_dose = {"null"};
	dosages(ace_doses, peds, ace_adult, ace_child, max, ace_max_dose);
	std::cout << "\n";
	break;}
    case 8: {std::cout << "Ibuprofen\n";
	std::vector<string> ibu_indications = {"mild", "moderate", "severe", "pain", "fever"};
	indications(ibu_indications);
	std::vector<string> ibu_contraindications = {"allergy", "NSAIDS", "pregnancy", "breastfeeding", "GI", "bleed", "blood thinners", "blood clotting disorder"};
	contraindications(ibu_contraindications);
	std::vector<string> ibu_doses = {"null"};
	peds = true;
	std::vector<string> ibu_adult = {"600", "mg", "PO"};
	std::vector<string> ibu_child = {"10", "mg/kg"};
	max = 0;
	std::vector<string> ibu_max_dose = {"null"};
	dosages(ibu_doses, peds, ibu_adult, ibu_child, max, ibu_max_dose);
	std::cout << "\n";
	break;}
    case 9: {std::cout << "Ipratropium Bromide\n";
	std::vector<string> ipr_indications = {"bronchospasm"};
	indications(ipr_indications);
	std::vector<string> ipr_contraindications = {"soy", "peanut", "allergy", "inhaler"};
	contraindications(ipr_contraindications);
	std::vector<string> ipr_doses = {"0.5", "mg", "with albuterol", "nebulizer"};
	peds = false;
	std::vector<string> ipr_adult = {"null"};
	std::vector<string> ipr_child = {"null"};
	max = 1;
	std::vector<string> ipr_max_dose = {"null"};
	dosages(ipr_doses, peds, ipr_adult, ipr_child, max, ipr_max_dose);
	std::cout << "\n";
	break;}
    case 10: {std::cout << "Ondansetron\n";
	std::vector<string> ond_indications = {"nausea", "vomiting"};
	indications(ond_indications);
	std::vector<string> ond_contraindications = {"with caution", "first", "trimester"};
	contraindications(ond_contraindications);
	std::vector<string> ond_doses = {"null"};
	peds = true;
	std::vector<string> ond_adult = {"4", "mg", "ODT"};
	std::vector<string> ond_child = {"2", "mg"};
	max = 0;
	std::vector<string> ond_max_dose = {"null"};
	dosages(ond_doses, peds, ond_adult, ond_child, max, ond_max_dose);
	std::cout << "\n";
	break;}
    case 11: {std::cout << "Phenylephrine\n";
	std::vector<string> phe_indications = {"epitaxis"};
	indications(phe_indications);
	std::vector<string> phe_contraindications = {"none"};
	contraindications(phe_contraindications);
	std::vector<string> phe_doses = {"2", "sprays"};
	peds = false;
	std::vector<string> phe_adult = {"null"};
	std::vector<string> phe_child = {"null"};
	max = 0;
	std::vector<string> phe_max_dose = {"null"};
	dosages(phe_doses, peds, phe_adult, phe_child, max, phe_max_dose);
	std::cout << "\n";
	break;}
      
    } // end of case/switch

  } // end of case/switch loop
  
  return 0;
}

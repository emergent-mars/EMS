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

// convert strings to lowercase for comparison
string tolowercase(string a){
  for(char &c : a){
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  }
  return a;
}


// universal answer check
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

// medication questions
void brand_name(vector<string> answer){
  std::cout << ">>  Brand name?\n";
  check_answer(answer);
}

void actions(vector<string> answer){
  std::cout << ">>  What does this drug do?\n";
  check_answer(answer);
}

void indications(vector<string> answer){
  std::cout << ">>  What are the indications for this drug?\n";
  check_answer(answer);
}
void contraindications(vector<string> answer){
  std::cout << ">>  What are the contraindications for this drug?\n";
  check_answer(answer);
}

void dosages(vector<string> answer){
  std::cout << ">>  What is the dosage for this drug? (include max dose if applicable)\n";
  check_answer(answer);
}

// conditions and disorders questions
void side_effects(vector<string> answer){
  std::cout << ">>  What are the side effects?\n";
  check_answer(answer);
}

void patho(vector<string> answer){
  std::cout << ">>  What is it?\n";
  check_answer(answer);
}

void signs(vector<string> answer){
  std::cout << ">>  What are important signs?\n";
  check_answer(answer);
}

void symptoms(vector<string> answer){
  std::cout << ">>  What are important symptoms?\n";
  check_answer(answer);
}

void treatment(vector<string> answer){
  std::cout << ">>  What would treatment for this condition be?\n";
  check_answer(answer);
}

int main(){
  
  bool yes = false;
  std::string q;
  int num_questions;
  std::vector<int> pool; // randomize in each question block w number of questions

  // NREMT drugs
  // asks for brand_name(), actions(), indications(), contraindications(), dosages(), side_effects()
  std::cout << "Review NREMT drugs? Y/N: ";
  std::cin >> q;
  std::cin.ignore();
  if(q == "Y" || q == "y"){yes = true;}
  if(yes){
    pool = random(6);
    for(int drug : pool){
      switch(drug){
      case 1: {std:cout << "Aspirin\n-\n";
	std::vector<string> asp_brand = {"bayer", "ecotrin"};
	brand_name(asp_brand);
	std::vector<string> asp_actions = {"inhibit", "platlet", "aggregation"};
	actions(asp_actions);
	std::vector<string> asp_indications = {"cardiac", "chest", "pain" };
	indications(asp_indications);
	std::vector<string> asp_contraindications = {"GI", "bleed", "allergy", "16", "unable", "swallow"};
	contraindications(asp_contraindications);
	std::vector<string> asp_dosage = {"324", "mg", "chewed"};
	dosages(asp_dosage);
	std::vector<string> asp_side_effects = {"heartburn"};
	side_effects(asp_side_effects);
	std::cout << "---\n";
	break;}
      case 2: {std::cout << "Albuterol\n-\n";
	  std::vector<string> alb_brand = {"proventil", "ventolin"};
	  brand_name(alb_brand);
	  std::vector<string> alb_actions = {"selective", "beta", "2", "adrnergic", "receptor", "agonist", "smooth", "muscle", "relaxant", "bronchodilaion"};
	  actions(alb_actions);
	  std::vector<string> alb_indications = {"respiratory", "distress", "bronchial asthma", "COPD", "bronchospasm"};
	  indications(alb_indications);
	  std::vector<string> alb_contraindications = {"severe", "tachycardia", "unable", "follow", "directions"};
	  contraindications(alb_contraindications);
	  std::vector<string> alb_dosage = {"SVN", "2.5 mg", "3 ml", "saline", "6-8", "LPM", "O2", "2 puffs"};
	  dosages(alb_dosage);
	  std::vector<string> alb_side_effects = {"increased HR", "tremors", "palpitations"};
	  side_effects(alb_side_effects);
	  std::cout << "---\n";
	  break;}
      case 3: {std::cout << "Epinephrine\n-\n";
	  std::vector<string> epi_brand = {"epipen", "twinject"};
	  brand_name(epi_brand);
	  std::vector<string> epi_actions = {"bronchodilation", "vasoconstriction"};
	  actions(epi_actions);
	  std::vector<string> epi_indications = {"anaphylactic", "respiratory", "distress"};
	  indications(epi_indications);
	  std::vector<string> epi_contraindications = {"none", "life-threatening"};
	  contraindications(epi_contraindications);
	  std::vector<string> epi_dosage = {"adults 0.3 mg", "peds 0.15 mg", "IM"};
	  dosages(epi_dosage);
	  std::vector<string> epi_side_effects = {"increased HR", "increased breathing", "hypertension", "anxiety", "increased MVO2", "chest pain"};
	  side_effects(epi_side_effects);
	  std::cout << "---\n";
	  break;}
      case 4: {std::cout << "Nalaxone\n-\n";
	  std::vector<string> nal_brand = {"narcan"};
	  brand_name(nal_brand);
	  std::vector<string> nal_actions = {"opioid", "receptor", "antagonist"};
	  actions(nal_actions);
	  std::vector<string> nal_indications = {"opioid", "CNS", "respiratory", "depression", "overdose"};
	  indications(nal_indications);
	  std::vector<string> nal_contraindications = {"none"};
	  contraindications(nal_contraindications);
	  std::vector<string> nal_dosage = {"0.5", "mg", "IN", "IV", "2 mg"};
	  dosages(nal_dosage);
	  std::vector<string> nal_side_effects = {"opioid withdrawal", "increased HR", "nausea", "vomiting", "pulmonary edema", "agitation"};
	  side_effects(nal_side_effects);
	  std::cout << "---\n";
	  break;}
      case 5: {std::cout << "Nitroglycerin\n-\n";
	  std::vector<string> nit_brand = {"nitrostat", "nitro-bid"};
	  brand_name(nit_brand);
	  std::vector<string> nit_actions = {"dilates blood vessels", "decrease", "workload", "heart", "decrease MVO2"};
	  actions(nit_actions);
	  std::vector<string> nit_indications = {"cardiac", "chest", "pain", "must be Pt Rx"};
	  indications(nit_indications);
	  std::vector<string> nit_contraindications = {"systolic below 100 mmHg", "ED", "last 24 hours", "BP drop of 30 mmHg after initial dose"};
	  contraindications(nit_contraindications);
	  std::vector<string> nit_dosage = {"0.4 mg", "tablet", "spray", "sublingual", "every 5min", "up to 1.2 mg"};
	  dosages(nit_dosage);
	  std::vector<string> nit_side_effects = {"hypotension", "headache", "syncope"};
	  side_effects(nit_side_effects);
	  std::cout << "---\n";
	  break;}
      case 6: {std::cout << "Oral Glucose\n-\n";
	  std::vector<string> glu_brand = {"glutose", "insta-glucose"};
	  brand_name(glu_brand);
	  std::vector<string> glu_actions = {"increase", "blood", "glucose"};
	  actions(glu_actions);
	  std::vector<string> glu_indications = {"hypoglycemia"};
	  indications(glu_indications);
	  std::vector<string> glu_contraindications = {"unable", "swallow"};
	  contraindications(glu_contraindications);
	  std::vector<string> glu_dosage = {"15", "g", "buccally"};
	  dosages(glu_dosage);
	  std::vector<string> glu_side_effects = {"none if administered properly"};
	  side_effects(glu_side_effects);
	  std::cout << "\n---\n";
	  break;}
      } // end of case/switch
    } // end of case/switch loop
  } // end of NREMT drugs

  // Denver Metro Drugs
  // asks for brand_name(), actions(), indications(), contraindications(), dosages(), side_effects()
  std::cout << "Review Denver Metro drugs? Y/N: ";
  std::cin >> q;
  std::cin.ignore();
  if(q == "Y" || q == "y"){yes = true;}
  if(yes){
    pool = random(5);
    for(int drug : pool){
      switch(drug){
      case 1: {std::cout << "Acetaminophen\n-\n";
	  std::vector<string> ace_brand = {"tylenol"};
	  brand_name(ace_brand);
	  std::vector<string> ace_actions = {"elevates pain threshold", "readjusts", "hypothalamic", "temperature-regulatory center"};
	  actions(ace_actions);
	  std::vector<string> ace_indications = {"mild", "moderate", "severe", "pain", "fever"};
	  indications(ace_indications);
	  std::vector<string> ace_contraindications = {"allergy", "chronic liver disease", "theraputic dose in the last 6 hours", "3 g in the last 24 hours"};
	  contraindications(ace_contraindications);
	  std::vector<string> ace_dosage = {"adult 1000 mg", "peds 15 mg/kg", "PO"};
	  dosages(ace_dosage);
	  std::vector<string> ace_side_effects = {"nausea", "vomiting", "hepatotoxicity", "overdose", "chronic alcohol"};
	  side_effects(ace_side_effects);
	  std::cout << "---\n";
	  break;}
      case 2: {std::cout << "Ibuprofen\n-\n";
	  std::vector<string> ibu_brand = {"motrin", "advil"};
	  brand_name(ibu_brand);
	  std::vector<string> ibu_actions = {"decrease", "pain", "inflammation"};
	  actions(ibu_actions);
	  std::vector<string> ibu_indications = {"mild", "moderate", "severe", "pain", "kidney stones", "chronic pain", "musculoskeletal pain", "fever"};
	  indications(ibu_indications);
	  std::vector<string> ibu_contraindications = {"allergy to NSAIDS", "pregnancy", "breastfeeding", "history of GI bleed", "active stomach ulcer", "chronic kidney disease", "kidney transplant", "blood thinners", "blood clotting disorder", "multisystem trauma", "acute head trauma", "intercranial bleed"};
	  contraindications(ibu_contraindications);
	  std::vector<string> ibu_dosage = {"adult 600 mg", "peds 10 mg/kg", "PO"};
	  dosages(ibu_dosage);
	  std::vector<string> ibu_side_effects = {"allergic reaction", "nausea", "vomiting", "GI bleeding with chronic use", "acute kidney injury"};
	  side_effects(ibu_side_effects);
	  std::cout << "---\n";
	  break;}
      case 3: {std::cout << "Ipratropium Bromide\n-\n";
	  std::vector<string> ipr_brand = {"atrovent"};
	  brand_name(ipr_brand);
	  std::vector<string> ipr_actions = {"bronchodilation"};
	  actions(ipr_actions);
	  std::vector<string> ipr_indications = {"bronchospasm"};
	  indications(ipr_indications);
	  std::vector<string> ipr_contraindications = {"soy", "peanut", "allergy", "in MDI"};
	  contraindications(ipr_contraindications);
	  std::vector<string> ipr_dosage = {"0.5 mg", "with albuterol", "nebulizer"};
	  dosages(ipr_dosage);
	  std::vector<string> ipr_side_effects = {"palpitations", "tremors", "dry mouth"};
	  side_effects(ipr_side_effects);
	  std::cout << "---\n";
	  break;}
      case 4: {std::cout << "Ondansetron\n-\n";
	  std::vector<string> ond_brand = {"zofran"};
	  brand_name(ond_brand);
	  std::vector<string> ond_actions = {"antiemetic"};
	  actions(ond_actions);
	  std::vector<string> ond_indications = {"nausea", "vomiting"};
	  indications(ond_indications);
	  std::vector<string> ond_contraindications = {"with caution", "first", "trimester"};
	  contraindications(ond_contraindications);
	  std::vector<string> ond_dosage = {"adult 4 mg", "peds 2 mg", "ODT"};
	  dosages(ond_dosage);
	  std::vector<string> ond_side_effects = {"none if administered properly"};
	  side_effects(ond_side_effects);
	  std::cout << "---\n";
	  break;}
      case 5: {std::cout << "Phenylephrine\n-\n";
	  std::vector<string> phe_brand = {"neo-synephrine"};
	  brand_name(phe_brand);
	  std::vector<string> phe_actions = {"decrease", "nose", "bleed"};
	  actions(phe_actions);
	  std::vector<string> phe_indications = {"epitaxis"};
	  indications(phe_indications);
	  std::vector<string> phe_contraindications = {"none"};
	  contraindications(phe_contraindications);
	  std::vector<string> phe_dosage = {"2 sprays"};
	  dosages(phe_dosage);
	  std::vector<string> phe_side_effects = {"nasal dryness", "burning or stinging"};
	  side_effects(phe_side_effects);
	  std::cout << "---\n";
	  break;}
      } // end of case/switch
    } // end of case/switch loop
  } // end of metro drugs
  
  // Respiratory Conditions
  // asks for patho(), signs(), symptoms(), treatment()
  std::cout << "Review respiratory conditions? Y/N: ";
  std::cin >> q;
  std::cin.ignore();
  if(q == "Y" || q == "y"){yes = true;}
  if(yes){
    pool = random(12);
    std::cout << "Signs are what you notice in the patient.\nSymptoms are what the patient describes to you.\n\n";
    for(int condition : pool){
      switch(condition){
      case 1:{std::cout << "Emphysema\n-\n";
	  std::vector<string> emp_patho = {"air", "underneath", "skin"};
	  patho(emp_patho);
	  std::vector<string> emp_signs = {"barrel", "chest", "unproductive cough", "prolonged exhalation", "pursed lip breathing", "diminished", "wheezing", "ronchi", "dyspnea on exertion", "pink skin", "tachypneic", "tachycardic", "tripod", "rice krispies on palpation"};
	  signs(emp_signs);
	  std::cout << "---\n";
	  break;}
      case 2:{std::cout << "Chronic BronchitiS\n-\n";
	  std::vector<string> chb_patho = {"inflammation", "airways"};
	  patho(chb_patho);
	  std::vector<string> chb_signs = {"overweight", "chronic cyanosis", "mild dyspnea", "productive cough", "coarse ronchi", "wheezing", "crackles", "frequent episodes of respiratory infections"};
	  signs(chb_signs);
	  std::cout << "---\n";
	  break;}
      case 3:{std::cout << "Asthma\n-\n";
	  std::cout << "---\n";
	  break;}
      case 4:{std::cout << "Pneumonia\n-\n";
	  std::cout << "---\n";
	  break;}
      case 5:{std::cout << "Pulmonary Embolism\n-\n";
	  std::cout << "---\n";
	  break;}
      case 6:{std::cout << "Pulmonary Edema\n-\n";
	  std::cout << "---\n";
	  break;}
      case 7:{std::cout << "Pneumothorax\n-\n";
	  std::cout << "---\n";
	  break;}
      case 8:{std::cout << "Hyperventilation\n-\n";
	  std::cout << "---\n";
	  break;}
      case 9:{std::cout << "Epiglottitis\n-\n";
	  std::cout << "---\n";
	  break;}
      case 10:{std::cout << "Pertussis\n-\n";
	  std::cout << "---\n";
	  break;}
      case 11:{std::cout << "Cystic Fibrosis\n-\n";
	  std::cout << "---\n";
	  break;}
      case 12:{std::cout << "Upper Respiratory Infection\n-\n";
	  std::cout << "---\n";
	  break;}
      } // end case/switch
    } // end question loop
  } // end of respiratory conditions
  
  
  return 0;
}

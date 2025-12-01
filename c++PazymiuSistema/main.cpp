#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;
int a;

class Naudotojai {

    protected:

    string vardas;
    string pavarde;
    string id;
    string role;

    public:

    Naudotojai(){}

    Naudotojai(string a, string b, string c, string d) : id(a),vardas(b), pavarde(c), role(d) {}

    void setVardas(string v) {
        this->vardas = v;
    }
    void setPavarde(string v) {
        this->pavarde = v;
    }
    void setId(int v) {
        this->id = v;
    }
    void setRole(string c) {
        this->role = c;
    }

    string getVardas() {
        return vardas;
    }
    string getPavarde() {
        return pavarde;
    }
    string getId() {
        return id;
    }
    string getRole() {
        return role;
    }

};

vector<Naudotojai> naudotojuSarasas = {
    Naudotojai("0","Jonas", "Jonaitis", "Studentas"),
    Naudotojai("1","Ona", "Petrauskaite", "Studentas"),
    Naudotojai("2","Marius", "Kazlauskas", "Studentas"),
    Naudotojai("3","Greta", "Paulauskyte", "Studentas"),
    Naudotojai("4","Tomas", "Vilkas", "Studentas"),
    Naudotojai("5","Laura", "Rimkute", "Studentas"),
    Naudotojai("6","Simonas", "Petraitis", "Destytojas"),
    Naudotojai("7","Egle", "Simkute", "Destytojas"),
    Naudotojai("8","Ieva", "Jonaite", "Administratorius"),
};


class Studentai: public Naudotojai {

    protected:

    string studentai_id;
    string naudotojaiStudentai_id;
    string grupe;

    public:

    Studentai() {}
    Studentai(string a, string b, string c): studentai_id(a), naudotojaiStudentai_id(b), grupe(c) {}

    virtual void setGrupe(string v) {
        this->grupe = v;
    }
    virtual string getGrupe() {
        return grupe;
    }
    void setStudentai_id(string v) {
        this->studentai_id = v;
    }
    string getStudentai_id() {
        return studentai_id;
    }
    string getNaudotojaiStudentai_id() {
        return naudotojaiStudentai_id;
    }

};

vector<Studentai> studentuSarasas = {
    Studentai("0", "0","PI24"),
    Studentai("1", "1","PI24"),
    Studentai("2", "2","PI25"),
    Studentai("3", "3","PI25"),
    Studentai("4", "4","IS25"),
    Studentai("5", "5","IS25"),

};


class Dalykai: public Studentai {

    protected:

    string dalykai_id;
    string dalykas;
    string grupe;
    string destytojaiDalykai_id;

    public:

    Dalykai() {}
    Dalykai(string a, string b, string c, string d): dalykai_id(a), destytojaiDalykai_id(b),grupe(c), dalykas(d) {}

    void setDalykas(string v) {
        this->dalykas = v;
    }
    void setDalykai_id(string v) {
        this->dalykai_id = v;
    }
    void setdestytojaiDalykai_id(string v) {
        this->destytojaiDalykai_id = v;
    }
    void setGrupe(string v) override {
        this->grupe=v;
    }
    string getDalykas() {
        return dalykas;
    }
    string getDalykai_id() {
        return dalykai_id;
    }
    string getDestytojaiDalykai_id() {
        return destytojaiDalykai_id;
    }
    string getGrupe() override {
        return grupe;
    }

};

vector<Dalykai> grupiuDalykai = {
    Dalykai("0", "6","PI24", "Duomenu baziu projektavimas"),
    Dalykai("1", "6","PI24", "Objektinis projektavimas"),
    Dalykai("2", "6","PI24", "Teise"),
    Dalykai("3", "6","PI25", "Operacines sistemos"),
    Dalykai("4", "7","PI25", "Matematika"),
    Dalykai("5", "7","PI25", "Diskrecioji atematika"),
    Dalykai("6", "7","PI25", "Operacines sistemos"),
};


class Pazymiai: public Dalykai {

    protected:

    string pazymiai_id;
    string dalykaiPazymiai_id;
    string studentaiPazymiai_id;
    string aprasymas;
    int pazymys;

    public:

    Pazymiai() {}
    Pazymiai(string a, string b, string c, string d, int e):pazymiai_id(a), dalykaiPazymiai_id(b), studentaiPazymiai_id(c),aprasymas(d), pazymys(e) {}

    void setAprasymas(string v) {
        this->aprasymas = v;
    }
    void setPazymys(int v) {
        this->pazymys = v;
    }
    void setPazymiai_id(string v) {
        this->pazymiai_id = v;
    }
    void setStudentaiPazymiai_id(string v) {
        this->studentaiPazymiai_id = v;
    }
    string getAprasymas() {
        return aprasymas;
    }
    int getPazymys() {
        return pazymys;
    }
    string getPazymiai_id() {
        return pazymiai_id;
    }
    string getDalykaiPazymiai_id() {
        return dalykaiPazymiai_id;
    }
    string getStudentaiPazymiai_id() {
        return studentaiPazymiai_id;
    }
};

vector<Pazymiai> pazymiuSarasas = {
    Pazymiai("0", "0","0","Kontrolinis darbas", 10),
    Pazymiai("1", "0","0","Savarankiskas darbas", 8),
    Pazymiai("2", "0","0","Projektinis darbas", 7),
    Pazymiai("3", "1","1","Praktinis darbas", 6),
    Pazymiai("4", "1","1","Kontrolinis darbas", 8),
    Pazymiai("5", "3","2","Savarankiskas darbas", 6)
};


class Destytojai: public Naudotojai {

    protected:

    string destytojai_id;
    string naudotojaiDestytojai_id;
    string priklausancios_grupes;
    string priklausantys_dalykai;

    public:

    Destytojai() {}
    Destytojai(string a, string b, string c, string d): destytojai_id(a), naudotojaiDestytojai_id(b), priklausancios_grupes(c), priklausantys_dalykai(d) {}
    Destytojai(string a, string b, string c): destytojai_id(a), naudotojaiDestytojai_id(b), priklausancios_grupes(c) {}

    void setDestytojai_id(string v) {
        this->destytojai_id = v;
    }
    void setNaudotojaiDestytojai_id(string v) {
        this->naudotojaiDestytojai_id = v;
    }
    void setPriklausancios_grupes(string v) {
        this->priklausancios_grupes = v;
    }
    void setPriklausantys_dalykai(string v) {
        this->priklausantys_dalykai = v;
    }
    string getDestytojai_id() {
        return destytojai_id;
    }
    string getNaudotojaiDestytojai_id() {
        return naudotojaiDestytojai_id;
    }
    string getPriklausancios_grupes() {
        return priklausancios_grupes;
    }
    string getPriklausantys_dalykai() {
        return priklausantys_dalykai;
    }
};

vector<Destytojai> priklausanciuDalykuSarasas = {
    Destytojai("0", "6", "PI24", "Duomenu baziu projektavimas"),
    Destytojai("1", "6", "PI24", "Teise"),
    Destytojai("2", "6", "PI25", "Operacines sistemos"),
    Destytojai("3", "7", "PI24", "Objektinis programavimas"),
    Destytojai("4", "7", "PI24", "Diskrecioji matematika"),
    Destytojai("5", "7", "PI25", "Matematika"),

};

vector<Destytojai> priklausanciuGrupiuSarasas = {
    Destytojai("0","6", "PI24"),
    Destytojai("1","6", "PI25"),
    Destytojai("2","7", "PI24"),
    Destytojai("3","7", "PI25"),
};


int main() {

    Naudotojai a;
    Studentai s;
    Dalykai d;
    Pazymiai p;

    string vardas, pavarde, dalykas;

    string v;
    string choice;
    string subchoice;

    while (true) {
        cout<<"Irasykite varda: "<<endl;
        cin>>v;
        a.setVardas(v);

        cout<<"Irasykite slaptazodi: "<<endl;
        cin>>v;
        a.setPavarde(v);

        string pilnasVardas=a.getVardas() + " " + a.getPavarde();

        cout<<"Jeigu norite iseiti is programos parasykite 'exit'"<<endl;
        cout<<"Jeigu norite testi parasykite 'a'"<<endl;
        cin>>choice;
        if (choice=="exit") {
            break;
        }
        for(int i=0; i<naudotojuSarasas.size(); i++) {
            if (naudotojuSarasas[i].getVardas() + " " + naudotojuSarasas[i].getPavarde()==pilnasVardas) {
                string aNaudotojoID = naudotojuSarasas[i].getId();
                string aStudentoGrupe;

                for (int s=0; s<studentuSarasas.size(); s++) {
                    if (studentuSarasas[s].getNaudotojaiStudentai_id()==aNaudotojoID) {
                        aStudentoGrupe=studentuSarasas[s].getGrupe();
                        break;
                    }
                }

                if (naudotojuSarasas[i].getRole()=="Studentas") {

                    while (true) {

                        cout<<"Studentas: "<<naudotojuSarasas[i].getVardas()<<" "<<naudotojuSarasas[i].getPavarde()<<endl;
                        cout<<endl;
                        cout<<"Grupe: "<<aStudentoGrupe<<endl;
                        cout<<endl;

                        for(int j=0; j<grupiuDalykai.size(); j++) {        //Atspausdina visus grupes dalykus
                            if (grupiuDalykai[j].getGrupe()==aStudentoGrupe) {
                                cout<<j<<". "<<grupiuDalykai[j].getDalykas()<<endl;
                            }
                        }
                        cout<<"----------------------------------------"<<endl;
                        cout<<"Irasykite dalyko skaicu, arba 'back', jeigu norite atsijungti: "<<endl;
                        cin>>choice;
                        if (choice=="back") break;

                        int aPasirinktasDalykas = stoi(choice);
                        string aPasirinktasDalykasID = grupiuDalykai[aPasirinktasDalykas].getDalykai_id();

                        while (true) {

                            cout<<grupiuDalykai[stoi(choice)].getDalykas()<<" pazymiai:"<<endl;
                            cout<<endl;

                            for(int k=0; k<pazymiuSarasas.size(); k++) {     //Atspausdina visus to dalyko pazymius
                                if (pazymiuSarasas[k].getDalykaiPazymiai_id()==aPasirinktasDalykasID && pazymiuSarasas[k].getStudentaiPazymiai_id()==aNaudotojoID) {
                                    cout<<pazymiuSarasas[k].getAprasymas()<<" "<<pazymiuSarasas[k].getPazymys()<<endl;
                                }
                            }
                            cout<<endl;
                            cout<<"----------------------------------------"<<endl;
                            cout<<"Irasykite 'back', kad galetumete grizti"<<endl;
                            cin>>choice;
                            if (choice=="back") break;
                        }
                    }
                }


                else if (naudotojuSarasas[i].getRole() == "Destytojas") {
                    while (true) {
                        cout<<"Destytojas: "<<naudotojuSarasas[i].getVardas()<<" "<<naudotojuSarasas[i].getPavarde()<<endl;

                        string aDestytojo_id = naudotojuSarasas[i].getId();
                        vector<string> vDestytojo_grupes; //Laikomos destytojo grupes
                        for (int j=0; j<priklausanciuGrupiuSarasas.size(); j++) {                     //Atspausdinamos destytojo grupes
                            if (priklausanciuGrupiuSarasas[j].getNaudotojaiDestytojai_id()==aDestytojo_id) {
                                cout<<vDestytojo_grupes.size()<<". "<<priklausanciuGrupiuSarasas[j].getPriklausancios_grupes()<<endl;
                                vDestytojo_grupes.push_back(priklausanciuGrupiuSarasas[j].getPriklausancios_grupes());
                            }
                        }
                        if (vDestytojo_grupes.size() == 0) {
                            cout<<"Jums nepriklauso jokios grupes."<<endl;
                            break;
                        }
                        cout<<"----------------------------------------"<<endl;
                        cout<<"Irasykite grupes skaicu, arba 'back', jeigu norite atsijungti: "<<endl;
                        cin>>choice;
                        if (choice=="back") break;

                        int grupes_index = stoi(choice);
                        if (grupes_index<0 || grupes_index>=vDestytojo_grupes.size()) continue;
                        string aPasirinktaGrupe = vDestytojo_grupes[grupes_index];

                        while (true){

                            // Show teacher's subjects for the group
                            vector<string> vDalykai_ids; // store subject ids
                            vector<string> vDalykuVardai; // store subject names

                            cout<<aPasirinktaGrupe<<" dalykai:"<<endl;
                            cout<<endl;
                            for (int k = 0; k < grupiuDalykai.size(); k++) {
                                if (grupiuDalykai[k].getDestytojaiDalykai_id()==aDestytojo_id && grupiuDalykai[k].getGrupe()==aPasirinktaGrupe) {   //Atspausdinami visi dalykai
                                    cout<<vDalykai_ids.size()<<". "<<grupiuDalykai[k].getDalykas()<<endl;
                                    vDalykai_ids.push_back(grupiuDalykai[k].getDalykai_id());
                                    vDalykuVardai.push_back(grupiuDalykai[k].getDalykas());
                                }
                            }

                            if (vDalykai_ids.size() == 0) {
                                cout<<"Siuo metu nera dalyku."<<endl;
                                break;
                            }

                            cout<<"----------------------------------------"<<endl;
                            cout<<"Irasykite dalyko skaicu, arba 'back', jeigu norite grizti: "<<endl;
                            cin>>choice;
                            if (choice=="back") break;

                            int dalykas_index = stoi(choice);
                            if (dalykas_index<0 || dalykas_index>=vDalykai_ids.size()) continue;
                            string aPasirinktasDalykasID = vDalykai_ids[dalykas_index];

                            vector<string> vStudentu_ids;
                            vector<string> vStudentuVardai;

                            for (int s=0; s<studentuSarasas.size(); s++) {     //Atspausdinami visi tos grupes studentai
                                if (studentuSarasas[s].getGrupe()==aPasirinktaGrupe) {
                                    string naudotojai_id = studentuSarasas[s].getNaudotojaiStudentai_id();
                                    for (int n=0; n<naudotojuSarasas.size(); n++) {
                                        if (naudotojuSarasas[n].getId()==naudotojai_id) {
                                            cout<<vStudentu_ids.size()<<". "<<naudotojuSarasas[n].getVardas()<<" "<<naudotojuSarasas[n].getPavarde()<<endl;
                                            vStudentu_ids.push_back(studentuSarasas[s].getStudentai_id());
                                            vStudentuVardai.push_back(naudotojuSarasas[n].getVardas() + " " + naudotojuSarasas[n].getPavarde());
                                            break;
                                        }
                                    }
                                }
                            }

                            if (vStudentu_ids.size() == 0) {
                                cout<<"Siuo metu nera studentu."<<endl;
                                continue;
                            }

                            cout<<endl;
                            cout<<"----------------------------------------"<<endl;
                            cout<<"Irasykite studento skaicu, arba 'back', jeigu norite grizti: "<<endl;
                            cin>>choice;
                            if (choice=="back") break;

                            int student_index = stoi(choice);
                            if (student_index< 0 || student_index>=vStudentu_ids.size()) continue;
                            string aPasirinktasStudentasID = vStudentu_ids[student_index];
                            string aPasirinktasStudentasVardas = vStudentuVardai[student_index];


                            subchoice = "";
                            while (subchoice!="back") {
                                cout<<"----------------------------------------"<<endl;
                                cout<<aPasirinktasStudentasVardas<<":"<<endl;
                                cout<<"Ka noresite daryti?"<<endl;
                                cout<<"1. Redaguoti pazymi"<<endl;
                                cout<<"2. Pasalinti pazymi"<<endl;
                                cout<<"3. Prideti nauja pazymi"<<endl;
                                cout<<"----------------------------------------"<<endl;
                                cout<<"Irasykite skaicu (1-3), arba 'back', jeigu norite grizti: "<<endl;
                                cin>>subchoice;

                                if (subchoice=="1") {
                                    while (true) {
                                        vector<int> vPazymiu_ids;
                                        for (int p = 0; p < pazymiuSarasas.size(); p++) {
                                            if (pazymiuSarasas[p].getDalykaiPazymiai_id()==aPasirinktasDalykasID &&         //Atspausdinami pazymiai
                                                pazymiuSarasas[p].getStudentaiPazymiai_id()==aPasirinktasStudentasID) {
                                                cout<<vPazymiu_ids.size()<<". "<<pazymiuSarasas[p].getAprasymas()<<": "<<pazymiuSarasas[p].getPazymys()<<endl;
                                                vPazymiu_ids.push_back(p);
                                                }
                                        }
                                        cout<<"----------------------------------------"<<endl;
                                        cout<<"Irasykite pazymio skaicu, arba 'back', jeigu norite grizti: "<<endl;
                                        cin>>choice;
                                        if (choice=="back") break;
                                        int pasirinktasPazymys_id = stoi(choice);
                                        if (pasirinktasPazymys_id<0 || pasirinktasPazymys_id>=vPazymiu_ids.size()) continue;
                                        int aPasirinktasPazymys = vPazymiu_ids[pasirinktasPazymys_id];

                                        cout<<"Pasirinkote: "<<pazymiuSarasas[aPasirinktasPazymys].getAprasymas()<<": "<<pazymiuSarasas[aPasirinktasPazymys].getPazymys()<<endl;
                                        cout<<"Irasykite nauja pazymi:"<<endl;
                                        cin>>choice;
                                        int aNaujasPazymys = stoi(choice);
                                        pazymiuSarasas[aPasirinktasPazymys].setPazymys(aNaujasPazymys);
                                        subchoice = "back";
                                        break;
                                    }
                                } else if (subchoice=="2") {
                                    while (true) {
                                        vector<int> vPazymiai_ids;
                                        for (int p=0; p<pazymiuSarasas.size(); p++) {
                                            if (pazymiuSarasas[p].getDalykaiPazymiai_id()==aPasirinktasDalykasID &&     //Atspausdinami pazymiai
                                                pazymiuSarasas[p].getStudentaiPazymiai_id()==aPasirinktasStudentasID) {
                                                cout<<vPazymiai_ids.size()<<". "<<pazymiuSarasas[p].getAprasymas()<<": "<<pazymiuSarasas[p].getPazymys()<<endl;
                                                vPazymiai_ids.push_back(p);
                                                }
                                        }
                                        cout<<"----------------------------------------" << endl;
                                        cout<<"Irasykite pazymio skaicu, arba 'back', jeigu norite grizti: "<<endl;
                                        cin>>choice;
                                        if (choice=="back") break;

                                        int pasirinktasPazymys_i = stoi(choice);
                                        if (pasirinktasPazymys_i<0 || pasirinktasPazymys_i>=vPazymiai_ids.size()) continue;
                                        int aPasirinktasPazymys = vPazymiai_ids[pasirinktasPazymys_i];

                                        cout<<"Pasalintas: "<<pazymiuSarasas[aPasirinktasPazymys].getAprasymas()<<": "<<pazymiuSarasas[aPasirinktasPazymys].getPazymys()<<endl;

                                        pazymiuSarasas.erase(pazymiuSarasas.begin() + aPasirinktasPazymys);
                                        subchoice = "back";
                                        break;
                                    }
                                } else if (subchoice=="3") {
                                    string aprasymas;
                                    int pazymys;
                                    cout<<"Irasykite aprasyma(savarankiskasis, projektinis, kontrolinis darbas):"<<endl;
                                    cin.ignore();
                                    getline(cin, aprasymas);

                                    cout<<"Irasykite pazymi: "<<endl;
                                    cin>>pazymys;

                                    string aNaujasPazymys_ID = to_string(pazymiuSarasas.size());
                                    pazymiuSarasas.push_back(Pazymiai(aNaujasPazymys_ID, aPasirinktasDalykasID, aPasirinktasStudentasID, aprasymas, pazymys));
                                    subchoice = "back";
                                    break;
                                } else if (subchoice=="back") {
                                    choice = "back";
                                } else {
                                    cout<<"Tokio pasirinkimo nera"<<endl;
                                }
                            }
                        }
                    }
                }


                else if (naudotojuSarasas[i].getRole()=="Administratorius") {
                    while (true) {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"Administratorius: "<<naudotojuSarasas[i].getVardas()<<" "<<naudotojuSarasas[i].getPavarde()<<endl;

                        cout<<endl;
                        cout<<"1. Sukurti studentu grupe"<<endl;
                        cout<<"2. Pasalinti studentu grupe"<<endl;
                        cout<<"3. Prideti studenta"<<endl;
                        cout<<"4. Pasalinti studenta"<<endl;
                        cout<<"5. Prideti destytoja"<<endl;
                        cout<<"6. Pasalinti destytoja"<<endl;
                        cout<<"7. Prideti dalyka"<<endl;
                        cout<<"8. Pasalinti dalyka"<<endl;

                        cout<<"----------------------------------------"<<endl;
                        cout<<"Irasykite pasirinkimo skaicu, arba 'back', jeigu norite atsijungti: "<<endl;
                        cin>>choice;
                        if (choice=="1") {
                            string aNaujosGrupesPavadinimas;

                            cout<<"Iveskite naujos grupes pavadinima: "<<endl;
                            cin>>aNaujosGrupesPavadinimas;

                            string aGrupe_id = to_string(priklausanciuGrupiuSarasas.size());

                            //Sukuriama grupe, destytojas yra tuscias
                            priklausanciuGrupiuSarasas.push_back(Destytojai(aGrupe_id, "", aNaujosGrupesPavadinimas));

                            cout<<"Nauja studentu grupe: "<<aNaujosGrupesPavadinimas<<" prideta"<<endl;
                            cout<<"----------------------------------------"<<endl;
                        }
                        else if (choice=="2") {

                            if (priklausanciuGrupiuSarasas.size() == 0) {
                                cout<<"Nera jokiu studentu grupiu, kurias galima pasalinti."<<endl;
                            } else {

                                cout<<"Pasirinkite grupe, kuri norite pasalinti:"<<endl;
                                cout<<endl;
                                set<string> vUnikaliosGrupes; //Laikomos unikalios grupes, kad nesikartotu
                                for (int i=0; i<priklausanciuGrupiuSarasas.size(); i++) {
                                    vUnikaliosGrupes.insert(priklausanciuGrupiuSarasas[i].getPriklausancios_grupes());
                                }

                                vector<string> vGrupes(vUnikaliosGrupes.begin(), vUnikaliosGrupes.end()); //Laikomos grupes kurios bus atspausdintos
                                for (int i=0; i<vGrupes.size(); i++) {
                                    cout<<i<<". "<<vGrupes[i]<<endl; //Atspausdinamos grupes
                                }
                                cout<<endl;
                                cout<<"----------------------------------------"<<endl;
                                cout<<"Iveskite grupes skaiciu arba 'back', jei norite grizti atgal: "<<endl;
                                cin>>subchoice;
                                if (subchoice=="back") break;

                                int aGrupes_id = stoi(subchoice);

                                if (aGrupes_id<0 || aGrupes_id>=vGrupes.size()) {
                                    cout<<"Tokios grupes nera"<<endl;
                                    cout<<"----------------------------------------"<<endl;
                                }

                                else {
                                    string aPasalintaGrupe = vGrupes[aGrupes_id];


                                    vector<string> vStudentu_ids; //Surenkami studentu id's
                                    vector<string> vNaudotoju_ids; //Surenkami naudotoju id's
                                    for (int i=studentuSarasas.size()-1; i>=0; --i) {
                                        if (studentuSarasas[i].getGrupe()==aPasalintaGrupe) {
                                            vStudentu_ids.push_back(studentuSarasas[i].getStudentai_id());
                                            vNaudotoju_ids.push_back(studentuSarasas[i].getNaudotojaiStudentai_id());
                                            studentuSarasas.erase(studentuSarasas.begin()+i);
                                        }
                                    }

                                    for (int i = naudotojuSarasas.size()-1; i> 0; --i) { //Pasalinami studentai is naudotojuSarasas
                                        for (size_t j=0; j<vNaudotoju_ids.size(); ++j) {
                                            if (naudotojuSarasas[i].getId()==vNaudotoju_ids[j]) {
                                                naudotojuSarasas.erase(naudotojuSarasas.begin()+i);
                                                break;
                                            }
                                        }
                                    }

                                    for (int i = pazymiuSarasas.size()-1; i>=0; --i) {   //Pasalinami studentu pazymiai
                                        for (size_t j=0; j<vStudentu_ids.size(); ++j) {
                                            if (pazymiuSarasas[i].getStudentaiPazymiai_id()==vStudentu_ids[j]) {
                                                pazymiuSarasas.erase(pazymiuSarasas.begin()+i);
                                                break;
                                            }
                                        }
                                    }

                                    vector<string> vDalyku_ids; //Grupes dalykai pasalinami
                                    for (int i=grupiuDalykai.size()-1; i>=0; --i) {
                                        if (grupiuDalykai[i].getGrupe()==aPasalintaGrupe) {
                                            vDalyku_ids.push_back(grupiuDalykai[i].getDalykai_id());
                                            grupiuDalykai.erase(grupiuDalykai.begin()+i);
                                        }
                                    }

                                    for (int i=pazymiuSarasas.size()-1; i>=0; --i) {  //Dalyku pazymiai pasalinami
                                        for (size_t j=0; j<vDalyku_ids.size(); ++j) {
                                            if (pazymiuSarasas[i].getDalykaiPazymiai_id()==vDalyku_ids[j]) {
                                                pazymiuSarasas.erase(pazymiuSarasas.begin()+i);
                                                break;
                                            }
                                        }
                                    }

                                    for (int i=priklausanciuGrupiuSarasas.size()-1; i>=0; --i) {   //Pasalinama grupe is priklausanciuGrupiuSarasas
                                        if (priklausanciuGrupiuSarasas[i].getPriklausancios_grupes()==aPasalintaGrupe) {
                                            priklausanciuGrupiuSarasas.erase(priklausanciuGrupiuSarasas.begin() + i);
                                        }
                                    }

                                    cout<<"Grupe "<<aPasalintaGrupe<<" pasalinta"<<endl;
                                    cout<<"----------------------------------------"<<endl;
                                }
                            }
                        }
                        else if (choice=="3") {

                            while (true) {
                                set<string> vUnikaliosGrupes;  //Laikomos unikalios grupes
                                for (int i=0; i<priklausanciuGrupiuSarasas.size(); i++) {
                                    vUnikaliosGrupes.insert(priklausanciuGrupiuSarasas[i].getPriklausancios_grupes());
                                }
                                vector<string> vGrupes(vUnikaliosGrupes.begin(), vUnikaliosGrupes.end()); //Spausdinamos visos unikalios grupes
                                for (int i=0; i<vGrupes.size(); i++) {
                                    cout<<i<<". "<<vGrupes[i]<<endl;
                                }
                                cout<<endl;
                                cout<<"----------------------------------------"<<endl;
                                cout<<"Irasykite grupes skaicu, arba 'back', jeigu norite grizti atgal: "<<endl;
                                cin>>subchoice;

                                if (subchoice=="back") break;

                                string aGrupesPavadinimas = vGrupes[stoi(subchoice)];

                                cout<<"Irasykite varda: "<<endl;
                                cin>>vardas;
                                cout<<"Irasykite pavarde: "<<endl;
                                cin>>pavarde;


                                string aNaujoNaudotojo_ID = to_string(naudotojuSarasas.size());
                                string aNaujoStudento_ID = to_string(studentuSarasas.size());

                                naudotojuSarasas.push_back(Naudotojai(aNaujoNaudotojo_ID, vardas, pavarde, "Studentas")); //Iterpiama i naudotojuSarasas
                                studentuSarasas.push_back(Studentai(aNaujoStudento_ID, aNaujoNaudotojo_ID, aGrupesPavadinimas)); //Iterpaiama i studentuSarasas

                                cout<<"Pridetas studentas: "<<vardas<<" "<<pavarde<<endl;
                                cout<<"----------------------------------------"<<endl;
                                break;
                            }
                        }
                        else if (choice=="4") {
                            while (true) {

                                set<string> vUnikaliosGrupes;  //Laikomos unikalios grupes
                                for (int i=0; i<priklausanciuGrupiuSarasas.size(); i++) {
                                    vUnikaliosGrupes.insert(priklausanciuGrupiuSarasas[i].getPriklausancios_grupes());
                                }
                                vector<string> vGrupes(vUnikaliosGrupes.begin(), vUnikaliosGrupes.end());

                                cout<<"Galimos grupes:"<<endl; //Atspausdinamos grupes
                                cout<<endl;

                                for (int i=0; i<vGrupes.size(); i++) {
                                    cout<<i<<". "<<vGrupes[i]<<endl;
                                }

                                cout<<endl;
                                cout<<"----------------------------------------"<<endl;
                                cout<<"Irasykite grupes skaicu, arba 'back', jeigu norite grizti atgal: "<<endl;
                                cin>>subchoice;
                                if (subchoice=="back") break;

                                int aGrupe_ID = stoi(subchoice);

                                if (aGrupe_ID>=0 && aGrupe_ID<vGrupes.size()) {
                                    string pasirinktaGrupe = vGrupes[aGrupe_ID];
                                    cout<<"Studentai grupeje "<<pasirinktaGrupe<<":"<<endl;
                                    cout<<endl;

                                    vector<string> vStudentai_ids;
                                    vector<string> vStudentuVardai;
                                    for (int i=0; i<studentuSarasas.size(); i++) {
                                        if (studentuSarasas[i].getGrupe()==pasirinktaGrupe) {
                                            vStudentai_ids.push_back(studentuSarasas[i].getStudentai_id()); //Suranda studentu id's
                                            string naudotojai_id = studentuSarasas[i].getNaudotojaiStudentai_id();

                                            string pilnas_vardas = "";
                                            for (int j=0; j<naudotojuSarasas.size(); j++) {  //Suranda naudotojo varda
                                                if (naudotojuSarasas[j].getId()==naudotojai_id) {
                                                    pilnas_vardas=naudotojuSarasas[j].getVardas() + " " + naudotojuSarasas[j].getPavarde();
                                                    break;
                                                }
                                            }
                                            vStudentuVardai.push_back(pilnas_vardas);
                                            cout<<vStudentai_ids.size()-1<<". "<<pilnas_vardas<<endl;   //Visi grupes studentai atspausdinami
                                        }
                                    }

                                    if (vStudentai_ids.empty()) {
                                        cout<<"Sioje grupeje nera studentu"<<endl;
                                        cout<<"----------------------------------------"<<endl;
                                        continue;
                                    }

                                    cout<<endl;
                                    cout<<"----------------------------------------"<<endl;
                                    cout<<"Irasykite studento skaicu, arba 'back', jeigu norite grizti atgal: "<<endl;
                                    cin>>subchoice;
                                    if (subchoice=="back") break;

                                    int aPasirinktasStudentas = stoi(subchoice);
                                    if (aPasirinktasStudentas>=0 && aPasirinktasStudentas<vStudentai_ids.size()) {
                                        string aStudentai_id = vStudentai_ids[aPasirinktasStudentas];
                                        string aNaudotojai_id = "";

                                        for (auto& s : studentuSarasas) {  //Suranda naudotojo id
                                            if (s.getStudentai_id()==aStudentai_id) {
                                                aNaudotojai_id=s.getNaudotojaiStudentai_id();
                                                break;
                                            }
                                        }

                                        for (int i=pazymiuSarasas.size()-1; i>=0; --i) {  //Pasalina pazymius
                                            if (pazymiuSarasas[i].getStudentaiPazymiai_id()==aStudentai_id) {
                                                pazymiuSarasas.erase(pazymiuSarasas.begin()+i);
                                            }
                                        }

                                        for (int i=studentuSarasas.size()-1; i>=0; --i) {  //Pasalina studenta is studentuSarasas
                                            if (studentuSarasas[i].getStudentai_id()==aStudentai_id) {
                                                studentuSarasas.erase(studentuSarasas.begin()+i);
                                                break;
                                            }
                                        }

                                        for (int i = naudotojuSarasas.size()-1; i>=0; --i) {  //Pasalina is naudotojuSarasas
                                            if (naudotojuSarasas[i].getId()==aNaudotojai_id) {
                                                naudotojuSarasas.erase(naudotojuSarasas.begin()+i);
                                                break;
                                            }
                                        }

                                        cout<<"Studentas ir visi jo pazymiai pasalinti"<<endl;
                                        cout<<"----------------------------------------"<<endl;
                                        break;

                                    } else {
                                        cout<<"Tokio studento nera"<<endl;
                                    }
                                }
                                else {
                                    cout<<"Tokios grupes nera"<<endl;
                                }
                            }
                        }
                        else if (choice=="5") {
                            string vardas, pavarde;
                            cout<<"Iveskite destytojo varda: "<<endl;
                            cin>>vardas;
                            cout<<"Iveskite destytojo pavarde: "<<endl;
                            cin>>pavarde;

                            string aNaujoNaudotojo_ID = to_string(naudotojuSarasas.size());
                            naudotojuSarasas.push_back(Naudotojai(aNaujoNaudotojo_ID, vardas, pavarde, "Destytojas"));

                            cout<<"Pridetas destytojas: "<<vardas<<" "<<pavarde<<endl;
                            cout<<"----------------------------------------"<<endl;

                        }
                        else if (choice=="6") {

                            while (true) {
                                vector<int> vDestytoju_ids;
                                cout<<"Galimi destytojai:"<<endl;
                                cout<<endl;
                                for (int i=0; i<naudotojuSarasas.size(); i++) {
                                    if (naudotojuSarasas[i].getRole()=="Destytojas") {  //Atspausdinami visi destytojai
                                        vDestytoju_ids.push_back(i);
                                        cout<<vDestytoju_ids.size()-1<<". "<<naudotojuSarasas[i].getVardas()<<" "<<naudotojuSarasas[i].getPavarde()<<endl;
                                    }
                                }

                                if (vDestytoju_ids.empty()) {
                                    cout<<"Nera destytoju."<<endl;
                                    cout<<"----------------------------------------"<<endl;
                                    break;
                                }

                                cout<<endl;
                                cout<<"----------------------------------------"<<endl;
                                cout<<"Pasirinkite, kuri destytoja pasalinti pagal numeri, arba iveskte 'back': "<<endl;
                                cin>>subchoice;
                                if (subchoice=="back") break;

                                int aPasirinktasDestytojas = stoi(subchoice);
                                if (aPasirinktasDestytojas<0 || aPasirinktasDestytojas>=vDestytoju_ids.size()) {
                                    cout<<"Tokio destytojo nera" << endl;
                                    cout<<"----------------------------------------"<<endl;
                                    break;
                                }
                                string aDestytojo_ID = naudotojuSarasas[vDestytoju_ids[aPasirinktasDestytojas]].getId();

                                naudotojuSarasas.erase(naudotojuSarasas.begin() + vDestytoju_ids[aPasirinktasDestytojas]); //Pasalinamas destytojas is naudotoju sarasas

                                for (int i=0; i<priklausanciuGrupiuSarasas.size(); i++) {  //Destytojas atskirtas nuo grupiu
                                    if (priklausanciuGrupiuSarasas[i].getNaudotojaiDestytojai_id()==aDestytojo_ID) {
                                        priklausanciuGrupiuSarasas[i].setNaudotojaiDestytojai_id("");
                                    }
                                }

                                cout<<"Destytojas buvo pasalintas"<<endl;
                                cout<<"----------------------------------------"<<endl;
                                break;
                            }
                        }
                        else if (choice=="7") {

                            while (true) {
                                vector<int> vDestytoju_ids;
                                cout<<"Galimi destytojai:"<<endl;
                                cout<<endl;
                                for (int i=0; i<naudotojuSarasas.size(); i++) {
                                    if (naudotojuSarasas[i].getRole()=="Destytojas") { //Atspausdinami visi destytojai
                                        vDestytoju_ids.push_back(i);
                                        cout<<vDestytoju_ids.size()-1<<". "<<naudotojuSarasas[i].getVardas()<<" "<<naudotojuSarasas[i].getPavarde()<<endl;
                                    }
                                }

                                if (vDestytoju_ids.empty()) {
                                    cout<<"Nera destytoju. Neimanoma prideti dalyko."<<endl;
                                    cout<<"----------------------------------------"<<endl;
                                    break;
                                }

                                cout<<endl;
                                cout<<"----------------------------------------"<<endl;
                                cout<<"Irasykite destytojo numeri arba 'back':"<<endl;
                                cin>>subchoice;
                                if (subchoice == "back") break;

                                while (true) {

                                    int aPasirinktasDestytojas = stoi(subchoice);

                                    if (aPasirinktasDestytojas<0 || aPasirinktasDestytojas>=vDestytoju_ids.size()) {
                                        cout<<"Tokio destytojo nera"<<endl;
                                        cout<<"----------------------------------------"<<endl;
                                        break;
                                    }
                                    string destytojas_id = naudotojuSarasas[vDestytoju_ids[aPasirinktasDestytojas]].getId();


                                    set<string> vUnikaliosGrupes;
                                    for (int i=0; i<priklausanciuGrupiuSarasas.size(); i++) {
                                        vUnikaliosGrupes.insert(priklausanciuGrupiuSarasas[i].getPriklausancios_grupes());
                                    }
                                    vector<string> grupes(vUnikaliosGrupes.begin(), vUnikaliosGrupes.end());

                                    if (grupes.empty()) {
                                        cout<<"Nera grupiu."<<endl;
                                        cout<<"----------------------------------------"<<endl;
                                        break;
                                    }

                                    cout<<"Galimos grupes:"<<endl;    //Atspausdinamos grupes
                                    cout<<endl;
                                    for (int i=0; i<grupes.size(); i++) {
                                        cout<<i<<". "<<grupes[i]<<endl;
                                    }
                                    cout<<endl;
                                    cout<<"----------------------------------------"<<endl;
                                    cout<<"Irasykite grupes numeri, arba 'back' jeigu norite grizti:"<<endl;
                                    cin>>subchoice;
                                    if (subchoice=="back") break;

                                    int aPasirinktaGrupe = stoi(subchoice);

                                    if (aPasirinktaGrupe<0 || aPasirinktaGrupe>=grupes.size()) {
                                        cout<<"Tokios grupes nera"<<endl;
                                        cout<<"----------------------------------------"<<endl;
                                        break;
                                    }

                                    string grupesPavadinimas = grupes[aPasirinktaGrupe];

                                    string dalykas_pavadinimas;
                                    cout<<"Irasykite naujo dalyko pavadinima: "<<endl;  //Irasomas dalyko pavadinimas
                                    cin.ignore();
                                    getline(cin, dalykas_pavadinimas);

                                    string naujasDalykoId = to_string(grupiuDalykai.size()); //Iterpiamas naujas dalykas
                                    grupiuDalykai.push_back(Dalykai(naujasDalykoId, destytojas_id, grupesPavadinimas, dalykas_pavadinimas));

                                    cout<<"Naujas dalykas "<<dalykas_pavadinimas<<" priskirtas destytojui "<<naudotojuSarasas[vDestytoju_ids[aPasirinktasDestytojas]].getVardas()<<" "
                                         <<naudotojuSarasas[vDestytoju_ids[aPasirinktasDestytojas]].getPavarde()
                                         <<" ir grupei "<<grupesPavadinimas<<"."<<endl;
                                    cout<<"----------------------------------------"<<endl;
                                    break;
                                }
                            }
                        }
                        else if (choice=="8") {

                            while (true) {
                                set<string> vUnikaliosGrupes; //Laikomos unikalios grupes
                                for (int i=0; i<priklausanciuGrupiuSarasas.size(); i++) { //Iterpiamos unikalios grupes i unikaliosGrupes
                                    vUnikaliosGrupes.insert(priklausanciuGrupiuSarasas[i].getPriklausancios_grupes());
                                }
                                vector<string> grupes(vUnikaliosGrupes.begin(), vUnikaliosGrupes.end());

                                if (grupes.empty()) {
                                    cout<<"Nera grupiu."<<endl;
                                    cout<<"----------------------------------------"<<endl;
                                    break;
                                }

                                cout<<"Galimos grupes:"<<endl;
                                cout<<endl;
                                for (int i=0; i<grupes.size(); i++) {  //Atspausdinamos grupes
                                    cout<<i<<". "<<grupes[i]<<endl;
                                }
                                cout<<endl;
                                cout<<"----------------------------------------"<<endl;
                                cout<<"Irasykite grupes numeri arba 'back', jeigu norite grizti:"<<endl;
                                cin>>subchoice;
                                if (subchoice=="back") break;

                                while (true) {

                                    int aPasirinktaGrupe = stoi(subchoice);
                                    if (aPasirinktaGrupe<0 || aPasirinktaGrupe>=grupes.size()) {
                                        cout<<"Tokios grupes nera"<<endl;
                                        cout<<"----------------------------------------"<<endl;
                                        break;
                                    }

                                    string aGrupesPavadinimas = grupes[aPasirinktaGrupe];


                                    vector<int> vDalyku_ids;
                                    cout<<"Dalykai grupeje "<<aGrupesPavadinimas<<":"<<endl;
                                    cout<<endl;
                                    for (int i=0; i<grupiuDalykai.size(); i++) {  //Atspausdinami tos grupes dalykai
                                        if (grupiuDalykai[i].getGrupe()==aGrupesPavadinimas) {
                                            vDalyku_ids.push_back(i);
                                            cout<<vDalyku_ids.size()-1<<". "<<grupiuDalykai[i].getDalykas()<<endl;
                                        }
                                    }

                                    if (vDalyku_ids.empty()) {
                                        cout<<"Siuo metu nera dalyku sios grupes sarase."<<endl;
                                        cout<<"----------------------------------------"<<endl;
                                        break;
                                    }

                                    cout<<"----------------------------------------"<<endl;
                                    cout<<"Irasykite dalyko numeri arba 'back':"<<endl;
                                    cin>>subchoice;
                                    if (subchoice=="back") break;

                                    int aPasirinktasDalykas = stoi(subchoice);

                                    if (aPasirinktasDalykas<0 || aPasirinktasDalykas>=vDalyku_ids.size()) {
                                        cout<<"Tokio dalyko nera"<<endl;
                                        cout<<"----------------------------------------"<<endl;
                                        break;
                                    }

                                    int adalyku_id = vDalyku_ids[aPasirinktasDalykas];
                                    string aDalykas_ID = grupiuDalykai[adalyku_id].getDalykai_id();
                                    string aDalykoVardas = grupiuDalykai[adalyku_id].getDalykas();


                                    int pazymiuPradzia = pazymiuSarasas.size();
                                    for (int i=pazymiuSarasas.size()-1; i>=0; --i) { //Visi sio dalyko pazymiai yra pasalinami
                                        if (pazymiuSarasas[i].getDalykaiPazymiai_id()==aDalykas_ID) {
                                            pazymiuSarasas.erase(pazymiuSarasas.begin()+i);
                                        }
                                    }

                                    grupiuDalykai[adalyku_id].setdestytojaiDalykai_id(""); //Destytojas atskirtas nuo dalyko

                                    grupiuDalykai.erase(grupiuDalykai.begin() + adalyku_id); //Is grupes pasalinamas dalykas

                                    cout<<"Dalykas "<<aDalykoVardas<<" buvo pasalintas is grupes "<<aGrupesPavadinimas<< endl;
                                    cout<<"----------------------------------------"<<endl;
                                    break;
                                }
                            }
                        }
                        if (choice=="back") break;
                    }
                } else {
                    cout<<"Tokio naudotojo nera"<<endl;
                }
                break;
            }
        }
    }


    return 0;
}
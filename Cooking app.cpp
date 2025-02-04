#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Recipe class to hold recipe data
class Recipe {
public:
    Recipe(string name, vector<string> ingredients, string instructions) {
        this->name = name;
        this->ingredients = ingredients;
        this->instructions = instructions;
    }
    string getName() {
        return name;
    }
    vector<string> getIngredients() {
        return ingredients;
    }
    string getInstructions() {
        return instructions;
    }
private:
    string name;
    vector<string> ingredients;
    string instructions;
};

// Vector of recipe objects
vector<Recipe> recipes;

// Function to add new recipe
void addRecipe() {
    string name, ingredient, instructions;
    vector<string> ingredients;
    cout << "Enter recipe name: ";
    cin >> name;
    cout << "Enter recipe ingredients separated by commas: ";
    cin.ignore();
    getline(cin, ingredient);
    while (ingredient != "") {
        ingredients.push_back(ingredient);
        getline(cin, ingredient);
    }
    cout << "Enter recipe instructions: ";
    getline(cin, instructions);
    Recipe recipe(name, ingredients, instructions);
    recipes.push_back(recipe);
    cout << "Recipe added successfully!\n" << endl;
}

// Function to display all recipes
void displayRecipes() {
    if (recipes.empty()) {
        cout << "No recipes found!\n" << endl;
    }
    else {
        for (int i = 0; i < recipes.size(); i++) {
            cout << recipes[i].getName() << endl;
            cout << "Ingredients: ";
            vector<string> ingredients = recipes[i].getIngredients();
            for (int j = 0; j < ingredients.size(); j++) {
                cout << ingredients[j] << ", ";
            }
            cout << "\nInstructions: " << recipes[i].getInstructions() << "\n" << endl;
        }
    }
}
void search(){
    if (recipes.empty()) {
        cout << "No recipes to search from!\n" << endl;
    }
    else{
        string sname;
        cout<<"Enter Recipe to search: ";
        cin>>sname;
        for (int i=0;i<recipes.size();i++){
            if(recipes[i].getName()==sname){
                cout << recipes[i].getName() << endl;
            cout << "Ingredients: ";
            vector<string> ingredients = recipes[i].getIngredients();
            for (int j = 0; j < ingredients.size(); j++) {
                cout << ingredients[j] << ", ";
            }
            cout << "\nInstructions: " << recipes[i].getInstructions() << "\n" << endl;
            break;
            }else{
                cout<<"Recipe not found;\n";
            }


        }
    }
}
int main() {
    int choice;
    cout << "Welcome to the cooking app!\n" << endl;
    while (true) {
        cout << "1. Add recipe\n";
        cout << "2. Display all recipes\n";
        cout << "3. Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addRecipe();
            break;
        case 2:
            displayRecipes();
            break;
        case 3:
            search();
            break;
        case 4:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n" << endl;
            break;
        }
    }
}

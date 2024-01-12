#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;

class FBuser {
private:
    string name;
    vector< FBuser* > friends; //list of friends

public:
    //constructor
    FBuser(string name = "") : name(name){};

    //Method to add a friend
    void addFriend(FBuser &newFriend){
        //put new friend in the friend list of current user
        friends.push_back(&newFriend); 
        //put the current user in the friend list of the new friend
        newFriend.friends.push_back(this); 
    }

    //Show Friends
    void showFriends() {
        cout << "\nFriends of " << name << ": \n > ";
        //loop through all friends in the friend list
        for (FBuser *eachFriend: friends) { 
            cout << eachFriend->name << "    ";
        }
        cout << "\n";
    }


    //Show Friends of Friends
    void showFriendsOfFriends(){
        cout << "\nFriends of Friends of " << name << ": \n > ";
        for (FBuser *eachFriend: friends) { //go through each friend 
            for (FBuser *fof: eachFriend->friends) { //go through each friend of the friend
                if (fof != this) { //not include the user itself
                    cout << fof->name << "    ";
                }
            }
        }
        cout << "\n";
    }
    


    //Show Mutual Friends
    void showMutualFriends(FBuser &another) {
        cout << "\nMutual friends of " << name <<   
                " and " << another.name << ": \n > ";
        for (FBuser *myFriends: friends) {
        //go through each friend of current user
            for (FBuser *hisFriends: another.friends) {
            //go through each friend of the comparing user 
                if (myFriends == hisFriends) { 
                    cout << myFriends->name << "    ";
                }
            }

        }
    }
    
};



int main(){
    //Qa. Show friends
    FBuser harry("Harry"), peter("Peter"), john("John"), luna("Luna");
    harry.addFriend(peter);
    harry.addFriend(john);
    peter.addFriend(luna);
    peter.addFriend(john);

    harry.showFriends();
    luna.showFriends();

    //Qb. Show friends of friends
    harry.showFriendsOfFriends();

    //Qc. Show mutual friends
    harry.showMutualFriends(peter);
}
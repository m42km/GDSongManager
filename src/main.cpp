#include <iostream>
using namespace std;

void c_system(string cmd) {
    // introducing c_system: it does all the dirty conversion work for you
    system(cmd.c_str());
}

int main(int argc, char** argv) {

    system("title GD Song Manager");

    string gdSongFolder = "%localappdata%\\GeometryDash"; // TODO: Make this a setting (excluding %localappdata%)

    if (argc == 1) {

            /* No arguments?
    ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝
    ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇
    ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀
    ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀
    ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀
    ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ */

        cout << "Please use the song manager by clicking on a .gdsong file..." << endl;

    } else {
        string songLocation = argv[1]; // TODO: Check if file exists, prob gonna do that in next version

        // and now: the code i just copied from stackoverflow
        // https://stackoverflow.com/a/14266139


        string songID_old = songLocation;

        string splitChars = "\\";
        string curr;
        size_t pos = 0;

        while ((pos = songID_old.find(splitChars)) != string::npos) {
            curr = songID_old.substr(0, pos);
            songID_old.erase(0, pos + splitChars.length());
        }

        string songID = songID_old.substr(0, songID_old.find("."));
        /*                                             ^ Just put this here
                                                         It should fix everything i think */

        // then we will end up with just the song ID, that's it :D

        c_system("title GD Song Manager - " + songID);

        cout << "Installing " << songLocation << " @ " << songID << " ..." << endl;
        cout << "=============================================================================" << endl;

        c_system("copy " + songLocation + " " + gdSongFolder + " /Y"); // copy the song, use overwrite flag
        c_system("del " + gdSongFolder + "\\" + songID + ".mp3 > nul"); // delete old song if it exists
        c_system("rename " + gdSongFolder + "\\" + (songID + ".gdsong") + " " + (songID + ".mp3")); // finally, rename the song

        // c_system("del " + songLocation); //  TODO: make this a setting or somethin

        cout << "=============================================================================" << endl;
        cout << "Song has (probably) been installed. Re-enter the level/restart GD if needed" << endl;
        cout << "This window will close in a couple of seconds, goodbye ..." << endl;

    }

    system("pause");

    return 0;
}

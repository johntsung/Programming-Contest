/*
*        Starting Template for Custom Validator Programs
*       --------------------------------------------------
*
*        Entry point for code:
*
*               Line 55 -
*
*        In brief
*        ----------
*        1. Read the team output from STDIN
*
*        2. Read the input of the test case from stream *judge_input*
*           (if necessary)
*
*        3. Read the answer of the test case from stream *judge_ans*
*           (if necessary)
*
*        4. Handle unexpected input with care
*
*
*        To conclude a decision for the test
*        ------------------------------------
*        1. Call accept() to conclude that team output is correct
*        2. Call wa() to conclude that team output is wrong
*
*
*        Use diff_report(int,int) to report diff position between
*          judge answer and team output (if necessary)
*
*        If additional info is to be output,
*        use
*             correct_answer( formated_str, ... )   and
*             wrong_answer( formated_str, ... )
*
*        to print additional message to jury.
*
*/
#include<bits/stdc++.h>
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cassert>
//#include <cmath>
//#include <cstdarg>
using namespace std;

const int EXIT_AC = 42;
const int EXIT_WA = 43;

//
//  I/O streams
//
ifstream judge_input, judge_ans;
FILE *judge_message = NULL;
FILE *diff_pos = NULL;

//
//  Utility functions
//
void wa(), accept(), diff_report(int,int), judge_error(const char*, ...);
void correct_answer(const char*, ...), wrong_answer(const char*, ...);
template <typename Stream> void openfile(Stream&, const char*, const char*);
FILE *openfeedback(const char*, const char*, const char*);

const char *USAGE = "Usage: %s judge_in judge_ans feedback_dir [options] < team_out";

int main(int argc, char **argv)
{
    if( argc < 4 )
        judge_error(USAGE, argv[0]);
    judge_message = openfeedback(argv[3], "judgemessage.txt", argv[0]);
    diff_pos = openfeedback(argv[3], "diffposition.txt", argv[0]);

    openfile(judge_input, argv[1], argv[0]);
    openfile(judge_ans, argv[2], argv[0]);

    //
    //  Staring Point for Validator codes:
    //

    long long team_out;
    int temp;
    temp=scanf("%lld",&team_out);
    if(temp!=1){
        fprintf(stderr,"NO output\n");
        wa();
    }
    if(team_out<(1ll<<50)){
        fprintf(stderr,"The number is less than 2^50.\n");
        wa();
    }
    if(team_out>(1ll<<54)){
        fprintf(stderr,"The number is larger than 2^54.\n");
        wa();
    }
    for(long long i=2;i*i<=team_out;i++){
        if(team_out%i==0){
            fprintf(stderr,"The number is not prime.\nIt has a factor %lld\n",i);
            wa();
        }
    }
    char s[10000];
    if(scanf("%s",s)!=EOF){
        fprintf(stderr,"More output.\n");
        wa();
    }
    accept();
    //
    //  End of validator
    //

    return 0;
}


//
//      Standard Utility Functions
//

void accept()
{
    exit(EXIT_AC);
}

void wa()
{
    exit(EXIT_WA);
}

void diff_report(int judgeans_pos, int stdin_pos)
{
    if (diff_pos) {
        fprintf(diff_pos, "%d %d", judgeans_pos, stdin_pos);
    }
}

void wrong_answer(const char *err, ...) {
    va_list pvar;
    va_start(pvar, err);
    //fprintf(judgemessage, "Wrong answer on line %d of output (corresponding to line %d in answer file)\n",
    //        stdin_line, judgeans_line);
    vfprintf(judge_message, err, pvar);
    fprintf(judge_message, "\n");
    exit(EXIT_WA);
}

void correct_answer(const char *err, ...) {
    va_list pvar;
    va_start(pvar, err);
    vfprintf(judge_message, err, pvar);
    fprintf(judge_message, "\n");
    exit(EXIT_AC);
}

void judge_error(const char *err, ...) {
    va_list pvar;
    va_start(pvar, err);
    // If judgemessage hasn't been set up yet, write error to stderr
    if (!judge_message) judge_message = stderr;
    vfprintf(judge_message, err, pvar);
    fprintf(judge_message, "\n");
    assert(!"Judge Error");
}

template <typename Stream>
void openfile(Stream &stream, const char *file, const char *whoami) {
    stream.open(file);
    if (stream.fail()) {
        judge_error("%s: failed to open %s\n", whoami, file);
    }
}

FILE *openfeedback(const char *feedbackdir, const char *feedback, const char *whoami) {
    std::string path = std::string(feedbackdir) + "/" + std::string(feedback);
    FILE *res = fopen(path.c_str(), "w");
    if (!res) {
        judge_error("%s: failed to open %s for writing", whoami, path.c_str());
    }
    return res;
}

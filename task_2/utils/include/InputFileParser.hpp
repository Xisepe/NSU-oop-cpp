//
// Created by maxim on 23.10.2022.
//

#ifndef TASK_2_INPUTFILEPARSER_HPP
#define TASK_2_INPUTFILEPARSER_HPP
#include "Parser.hpp"
#include "GameSettings.hpp"

class InputFileParser: public Parser<GameSettings> {
private:
    inline static const std::string _FOLDER = "ASSETS/";
    inline static const std::string _DEFAULT_INPUT_NAME = "default_input.txt";
    std::string _filename;
    void throwCheckStreamState(const std::ifstream& in) const;
    bool checkInputFileFormat(const std::string& line) const;
    void evaluateInputFileFormat(bool res, std::ifstream &in) const;
    bool checkBornSurviveRules(const std::string& rule) const;
    void evaluateBornSurviveRules(bool res, std::ifstream &in) const;
    bool checkUniverseName(const std::string& rule) const;
    void evaluateUniverseName(bool res, std::ifstream &in) const;
    bool checkPair(const std::string&line) const;
    void evaluatePair(bool res, std::ifstream &in) const;

    std::string parseName(const std::string& line) const;
public:
    InputFileParser();

    InputFileParser(std::string filename);
    const std::string &getFilename() const;
    void setFilename(const std::string &filename);
    GameSettings parse() const override;
};


#endif //TASK_2_INPUTFILEPARSER_HPP

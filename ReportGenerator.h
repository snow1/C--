#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H


enum class ErrorLevel {
    Green,
    Yellow,
    Red
};

struct DiagnosticReport {
    bool has_issue;
    ErrorLevel level;
    std::string issue_message;
};

class ReportGenerator{
public:
    virtual const DiagnosticReport GenerateReport() = 0;
};

#endif // REPORT_GENERATOR_H
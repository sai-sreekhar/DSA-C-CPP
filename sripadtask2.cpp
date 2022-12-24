#include <string>
using namespace std;

namespace operators
{
    const char NEGATION{'~'};
    const char AND{'^'};
    const char OR{'V'};
    const char IMPLIES{'>'};
}

bool isOperand(char input)
{
    return input >= 'a' && input <= 'z';
}

bool isOperator(char input)
{
    using namespace operators;
    const char validOperators[] = {NEGATION, AND, OR, IMPLIES};
    for (int i = 0; i < 4; i++)
    {
        if (input == validOperators[i])
        {
            return true;
        }
    }

    return false;
}

int op_priority(char op)
{
    using namespace operators;

    switch (op)
    {
    case NEGATION:
        return 4;
    case AND:
    case OR:
        return 3;
    case IMPLIES:
        return 2;
    default:
        return -1;
    }
}

namespace verbs
{
    const char INTRODUCTION{'i'};
    const char ELIMINATION{'e'};
}

namespace rule_literals
{
    using namespace operators;
    string PREMISE{"P"};

    string AND_INTRODUCTION{AND, verbs::INTRODUCTION};
    string AND_ELIMINATION1{AND, verbs::ELIMINATION, '1'};
    string AND_ELIMINATION2{AND, verbs::ELIMINATION, '2'};
    string OR_INTRODUCTION1{OR, verbs::INTRODUCTION, '1'};
    string OR_INTRODUCTION2{OR, verbs::INTRODUCTION, '2'};
    string IMPLIES_ELIMINATION{IMPL, verbs::ELIMINATION}; 
    string MODUS_TOLLENS{"MODUS_TOLLENS"};                                  
}

bool check_validity(ProofLine *newline)
{
    using namespace rule_literals;
    if (newline->rule_literal == PREMISE)
        return check_valid_prem(newline);
    else if (newline->rule_literal == AND_INTRODUCTION)
        return check_valid_and_i(newline);
    else if (newline->rule_literal == AND_ELIMINATION1)
        return check_valid_and_e1(newline);
    else if (newline->rule_literal == AND_ELIMINATION2)
        return check_valid_AND_ELIMINATION2(newline);
    else if (newline->rule_literal == OR_INTRODUCTION1)
        return check_valid_or_i1(newline);
    else if (newline->rule_literal == OR_INTRODUCTION2)
        return check_valid_or_i2(newline);
    else if (newline->rule_literal == IMPLIES_ELIMINATION)
        return check_valid_impl_e(newline);
    else if (newline->rule_literal == MODUS_TOLLENS)
        return check_valid_mt(newline);
    else
        return false; // in case rule_literal doesn't match any valid rule_literals
}

/* Rest of the code is self explanatory due to proper variable naming.
   We check for equality of parse trees of the appropriate ProofLine objects by comparing their inorder traversal strings.
 */

bool check_valid_prem(ProofLine *newline)
{
    return !(newline->line1 or newline->line2);
}

bool check_valid_and_i(ProofLine *newline)
{
    if (!newline->line1 or !newline->line1->is_valid_formula)
        return false;
    if (!newline->line2 or !newline->line2->is_valid_formula)
        return false;
    return newline->formula->left->get_inorder() == newline->line1->formula->get_inorder() and
           newline->formula->right->get_inorder() == newline->line2->formula->get_inorder();
}

bool check_valid_and_e1(ProofLine *newline)
{
    if (newline->line2 or !newline->line1 or !newline->line1->is_valid_formula or newline->line1->formula->token != AND)
        return false;
    return newline->line1->formula->left->get_inorder() == newline->formula->get_inorder();
}

bool check_valid_AND_ELIMINATION2(ProofLine *newline)
{
    if (newline->line2 or !newline->line1 or !newline->line1->is_valid_formula or newline->line1->formula->token != AND)
        return false;
    return newline->line1->formula->right->get_inorder() == newline->formula->get_inorder();
}

bool check_valid_or_i1(ProofLine *newline)
{
    if (newline->line2 or !newline->line1 or !newline->line1->is_valid_formula)
        return false;
    return newline->line1->formula->get_inorder() == newline->formula->left->get_inorder();
}

bool check_valid_or_i2(ProofLine *newline)
{
    if (newline->line2 or !newline->line1 or !newline->line1->is_valid_formula)
        return false;
    return newline->line1->formula->get_inorder() == newline->formula->right->get_inorder();
}

bool check_valid_impl_e(ProofLine *newline)
{
    if (!newline->line1 or !newline->line1->is_valid_formula)
        return false;
    if (!newline->line2 or !newline->line2->is_valid_formula)
        return false;
    if (newline->line1->formula->token != IMPL)
        return false;
    return newline->line1->formula->left->get_inorder() == newline->line2->formula->get_inorder() and
           newline->line1->formula->right->get_inorder() == newline->formula->get_inorder();
}

bool check_valid_mt(ProofLine *newline)
{
    if (!newline->line1 or !newline->line1->is_valid_formula)
        return false;
    if (!newline->line2 or !newline->line2->is_valid_formula)
        return false;
    if (newline->line1->formula->token != IMPL)
        return false;
    if (newline->formula->token != NEG or newline->line2->formula->token != NEG)
        return false;
    return newline->line1->formula->left->get_inorder() == newline->formula->right->get_inorder() and
           newline->line1->formula->right->get_inorder() == newline->line2->formula->right->get_inorder();
}

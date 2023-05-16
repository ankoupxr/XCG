#pragma once

class Element
{
public:
    bool m_isSelected;
    bool m_isIn;
    bool m_isSub;
    unsigned int m_index;

public:
    Element(void);

public:
    virtual ~Element(void);
};
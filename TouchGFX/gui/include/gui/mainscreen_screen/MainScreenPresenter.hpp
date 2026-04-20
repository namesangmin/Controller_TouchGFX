#ifndef MAINSCREENPRESENTER_HPP
#define MAINSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainScreenView;

class currentState{
public:
	virtual ~currentState(){}
	virtual void update(MainScreenView& v, messageBuffer& msg){}
};

class ADCState : public currentState
{
private:
	const char* mode = "ADC Mode!";
public:
	void update(MainScreenView& v, messageBuffer& msg) override;
};

class JOYState : public currentState
{
private:
	const char* mode = "JoyStick Mode!";
public:
	void update(MainScreenView& v, messageBuffer& msg) override;
};

class MainScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MainScreenPresenter(MainScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    // 추가 //
    void notifyOutputData(messageBuffer& msg) override;
    void calculateRange(messageBuffer& msg);
    void choiceMode(messageBuffer& msg);

    virtual ~MainScreenPresenter() {}

private:
    MainScreenPresenter();

    MainScreenView& view;

    currentState *cState = nullptr;
    ADCState adcState;
    JOYState joyState;
};

#endif // MAINSCREENPRESENTER_HPP

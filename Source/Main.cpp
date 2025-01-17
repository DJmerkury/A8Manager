#include <JuceHeader.h>
#include "AppProperties.h"
#include "GUI/MainComponent.h"
#include "Utility/DebugLog.h"
#include "Utility/PersistentRootProperties.h"
#include "Utility/RootProperties.h"
#include "Utility/RuntimeRootProperties.h"
#include "Utility/ValueTreeFile.h"
#include "Assimil8or/Assimil8orValidator.h"
#include "Assimil8or/Preset/PresetProperties.h"

const juce::String PropertiesFileExtension { ".properties" };

void crashHandler (void* /*data*/)
{
    FlushDebugLog ();
    juce::Logger::writeToLog (juce::SystemStats::getStackBacktrace ());
    FlushDebugLog ();
}

class A8ManagerApplication : public juce::JUCEApplication, public juce::Timer
{
public:
    A8ManagerApplication () {}

    const juce::String getApplicationName () override { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion () override { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed () override { return true; }

    class ListenerLogger : public juce::ValueTree::Listener
    {
    public:
        void assign (juce::ValueTree& vtToListenTo)
        {
            vtBeingListened = vtToListenTo;
        }
    private:
        juce::ValueTree vtBeingListened;

        void valueTreePropertyChanged (juce::ValueTree& vt, const juce::Identifier& property) override
        {
            juce::Logger::outputDebugString ("valueTreePropertyChanged(" + vtBeingListened.getType ().toString () + ")");
            if (vt == vtBeingListened)
            {
                if (vt.hasProperty (property))
                {
                    // change in value
                    juce::Logger::outputDebugString ("  (property value changed) - property: " +
                                                     property.toString () + ", value: " + vt.getProperty (property).toString ());
                }
                else
                {
                    // property removed
                    juce::Logger::outputDebugString ("  (property removed) - property: " + property.toString ());
                }
            }
            else
            {
                if (vt.hasProperty (property))
                {
                    // change in value
                    juce::Logger::outputDebugString ("  (value changed) - vt: " + vt.getType ().toString () +
                                                     ", property: " + property.toString () + ", value: " + vt.getProperty (property).toString ());
                }
                else
                {
                    // property removed
                    juce::Logger::outputDebugString ("  (property removed) - vt: " + vt.getType ().toString () + ", property: " + property.toString ());
                }
            }
        };
        void valueTreeChildAdded (juce::ValueTree& vt, juce::ValueTree& child) override
        {
            juce::Logger::outputDebugString ("valueTreeChildAdded(" + vtBeingListened.getType ().toString () + ")");

            if (vt == vtBeingListened)
                juce::Logger::outputDebugString ("  child: " + child.getType ().toString ());
            else
                juce::Logger::outputDebugString ("  vt: " + vt.getType ().toString () + ", child: " + child.getType ().toString ());

        }
        void valueTreeChildRemoved (juce::ValueTree& vt, juce::ValueTree& child , int index) override
        {
            juce::Logger::outputDebugString ("valueTreeChildRemoved(" + vtBeingListened.getType ().toString () + ")");
            if (vt == vtBeingListened)
                juce::Logger::outputDebugString ("  child: " + child.getType ().toString () + ", index: " + juce::String (index));
            else
                juce::Logger::outputDebugString ("  vt: " + vt.getType ().toString () +
                                                 ", child: " + child.getType ().toString () + ", index: " + juce::String (index));
        }
        void valueTreeChildOrderChanged (juce::ValueTree& vt, int oldIndex, int newIndex) override
        {
            juce::Logger::outputDebugString ("valueTreeChildOrderChanged(" + vtBeingListened.getType ().toString () + ")");
            if (vt == vtBeingListened)
                juce::Logger::outputDebugString ("  old index: " + juce::String (oldIndex) + ", new index: " + juce::String (newIndex));
            else
                juce::Logger::outputDebugString ("  vt: " + vt.getType ().toString () +
                                                 ", old index: " + juce::String (oldIndex) + ", new index: " + juce::String (newIndex));
        }
        void valueTreeParentChanged (juce::ValueTree& vt) override
        {
            juce::Logger::outputDebugString ("valueTreeParentChanged(" + vtBeingListened.getType ().toString () + ")");
            if (vt == vtBeingListened)
            {
                if (vt.getParent ().isValid ())
                    juce::Logger::outputDebugString ("  new parent: " + vt.getParent ().getType ().toString ());
                else
                    juce::Logger::outputDebugString ("  (removed)");
            }
            else
            {
                if (vt.getParent ().isValid ())
                    juce::Logger::outputDebugString ("  vt: " + vt.getType ().toString () +
                                                     ", new parent: " + vt.getParent ().getType ().toString ());
                else
                    juce::Logger::outputDebugString ("  (removed) vt: " + vt.getType ().toString ());
            }
        }
        void valueTreeRedirected (juce::ValueTree& vt) override
        {
            juce::Logger::outputDebugString ("valueTreeRedirected(" + vtBeingListened.getType ().toString () + "): " + vt.getType ().toString ());
            vtBeingListened = vt;
            //if (vt == vtBeingListened)
        }
    };

    void valueTreeTest ()
    {
        juce::ValueTree root { "Root" };
        juce::ValueTree child1 { "RootChild1" };
        juce::ValueTree child2 { "RootChild2" };
        juce::ValueTree child3 { "RootChild3" };
        juce::ValueTree child4 { "RootChild4" };
        ListenerLogger rootListenerLogger;
        rootListenerLogger.assign (root);
        ListenerLogger child1ListenerLogger;
        child1ListenerLogger.assign (child1);
        ListenerLogger child2ListenerLogger;
        child2ListenerLogger.assign (child2);
        ListenerLogger child3ListenerLogger;
        child3ListenerLogger.assign (child3);
        root.addListener (&rootListenerLogger);
        child1.addListener (&child1ListenerLogger);
        child2.addListener (&child2ListenerLogger);
        child3.addListener (&child3ListenerLogger);

        auto basicPropertyTest = [] (juce::ValueTree& vt)
        {
            vt.setProperty ("propOne", "1", nullptr);
            vt.setProperty ("propOne", "2", nullptr);
            vt.removeProperty ("propOne", nullptr);
            vt.setProperty ("propTwo", "3", nullptr);
            vt.setProperty ("propThree", "4", nullptr);
        };
        basicPropertyTest (root);

        root.addChild (child1, -1, nullptr);
        basicPropertyTest (child1);
        child1.addChild (child2, -1, nullptr);
        child3.copyPropertiesAndChildrenFrom (child1, nullptr);
        child2 = child4;
        basicPropertyTest (child4);
        root.removeChild (child1, nullptr);
    }

    void initialise ([[maybe_unused]] const juce::String& commandLine) override
    {
        //valueTreeTest ();
        initAppDirectory ();
        initLogger ();
        initCrashHandler ();
        initPropertyRoots ();
        initAssimil8or ();
        initUi ();

        // async quit timer
        startTimer (125);
    }

    void shutdown () override
    {
        persitentPropertiesFile.save ();
        mainWindow = nullptr; // (deletes our window)
        juce::Logger::setCurrentLogger (nullptr);
    }

    void anotherInstanceStarted ([[maybe_unused]] const juce::String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

    void suspended () override
    {
        runtimeRootProperties.triggerAppSuspended (false);
    }

    void resumed () override
    {
        runtimeRootProperties.triggerAppResumed (false);
    }

    void systemRequestedQuit () override
    {
        // reset preferred quit state
        runtimeRootProperties.setPreferredQuitState (RuntimeRootProperties::QuitState::now, false);
        // listeners for 'onSystemRequestedQuit' can do runtimeRootPropertiesVT.setPreferredQuitState (RuntimeRootProperties::QuitState::idle);
        // if they need to do something, which also makes them responsible for calling runtimeRootPropertiesVT.setQuitState (RuntimeRootProperties::QuitState::now); when they are done...
        runtimeRootProperties.triggerSystemRequestedQuit (false);
        localQuitState.store (runtimeRootProperties.getPreferredQuitState ());
    }

    void timerCallback () override
    {
        if (localQuitState.load () == RuntimeRootProperties::QuitState::now)
            quit ();
    }

    void initAssimil8or ()
    {
        // hack the preset data on to the runtime root until we get a proper valuetreewrapper for the preset
        runtimeRootProperties.getValueTree ().addChild (presetProperties.getValueTree (), -1, nullptr);
        assimil8orValidator.init (runtimeRootProperties.getValueTree ());
    }

    void initUi ()
    {
        mainWindow.reset (new MainWindow (getApplicationName () + " - v" + getApplicationVersion (), rootProperties.getValueTree ()));
    }

    void initPropertyRoots ()
    {
        persistentRootProperties.wrap (rootProperties.getValueTree (), PersistentRootProperties::WrapperType::owner, PersistentRootProperties::EnableCallbacks::no);
        // connect the Properties file and the AppProperties ValueTree with the propertiesFile (ValueTreeFile with auto-save)
        persitentPropertiesFile.init (persistentRootProperties.getValueTree (), appDirectory.getChildFile ("app" + PropertiesFileExtension), true);
        appProperties.wrap (persistentRootProperties.getValueTree (), AppProperties::WrapperType::owner, AppProperties::EnableCallbacks::no);

        runtimeRootProperties.wrap (rootProperties.getValueTree (), RuntimeRootProperties::WrapperType::owner, RuntimeRootProperties::EnableCallbacks::no);
        runtimeRootProperties.setAppVersion (getApplicationVersion (), false);
        runtimeRootProperties.setAppDataPath (appDirectory.getFullPathName (), false);
    }

    void initAppDirectory ()
    {
        // locate the appProperties file in the User Application Data Directory

        //   On Windows, something like "\Documents and Settings\username\Application Data".
        //   On the Mac, it is "~/Library/Company".
        //   On GNU/Linux it is "~/.config".

        const juce::String propertiesFilePath { juce::File::getSpecialLocation (juce::File::userApplicationDataDirectory).getFullPathName () };
        appDirectory = juce::File (propertiesFilePath).getChildFile (ProjectInfo::companyName).getChildFile (getApplicationName ());
        if (! appDirectory.exists ())
        {
            const auto result { appDirectory.createDirectory () };
            if (! result.wasOk ())
            {
                juce::AlertWindow::showMessageBoxAsync (juce::AlertWindow::WarningIcon, "Application Startup Error",
                    "Unable to create " + getApplicationName () + " preferences directory, '" + appDirectory.getFullPathName () + "'", {}, nullptr,
                    juce::ModalCallbackFunction::create ([this] (int) { quit (); }));
                return;
            }
        }
    }

    void initLogger ()
    {
        auto getSessionTextForLogFile = [this] ()
        {
            auto resultOrNa = [] (juce::String result)
            {
                if (result.isEmpty ())
                    return juce::String ("n/a");
                else
                    return result;
            };
            const auto nl { juce::String ("\n") };
            auto welcomeText { juce::String (getApplicationName () + " - v" + getApplicationVersion () + " Log File" + nl) };
            welcomeText += " OS: " + resultOrNa (juce::SystemStats::getOperatingSystemName ()) + nl;
            welcomeText += " Device Description: " + resultOrNa (juce::SystemStats::getDeviceDescription ()) + nl;
            welcomeText += " Device Manufacturer: " + resultOrNa (juce::SystemStats::getDeviceManufacturer ()) + nl;
            welcomeText += " CPU Vendor: " + resultOrNa (juce::SystemStats::getCpuVendor ()) + nl;
            welcomeText += " CPU Model: " + resultOrNa (juce::SystemStats::getCpuModel ()) + nl;
            welcomeText += " CPU Speed: " + resultOrNa (juce::String (juce::SystemStats::getCpuSpeedInMegahertz ())) + nl;
            welcomeText += " Logical/Physicals CPUs: " + resultOrNa (juce::String (juce::SystemStats::getNumCpus ())) + "/" + resultOrNa (juce::String (juce::SystemStats::getNumPhysicalCpus ())) + nl;
            welcomeText += " Memory: " + resultOrNa (juce::String (juce::SystemStats::getMemorySizeInMegabytes ())) + "mb" + nl;
            return welcomeText;
        };
        fileLogger = std::make_unique<juce::FileLogger> (appDirectory.getChildFile ("DebugLog"), getSessionTextForLogFile ());
        juce::Logger::setCurrentLogger (fileLogger.get ());
    }

    void initCrashHandler ()
    {
        juce::SystemStats::setApplicationCrashHandler (crashHandler);
    }

    //==============================================================================
    /*
        This class implements the desktop window that contains an instance of
        our MainComponent class.
    */
    class MainWindow    : public juce::DocumentWindow
    {
    public:
        MainWindow (juce::String name, juce::ValueTree rootProperties)
            : DocumentWindow (name,
                              juce::Desktop::getInstance ().getDefaultLookAndFeel ().findColour (juce::ResizableWindow::backgroundColourId),
                              DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new MainComponent (rootProperties), true);

           #if JUCE_IOS || JUCE_ANDROID
            setFullScreen (true);
           #else
            setResizable (true, true);
            centreWithSize (getWidth (), getHeight ());
           #endif

            setVisible (true);
        }

        void closeButtonPressed () override
        {
            // This is called when the user tries to close this window. Here, we'll just
            // ask the app to quit when this happens, but you can change this to do
            // whatever you need.
            JUCEApplication::getInstance ()->systemRequestedQuit ();
        }

        /* Note: Be careful if you override any DocumentWindow methods - the base
           class uses a lot of them, so by overriding you might break its functionality.
           It's best to do all your work in your content component instead, but if
           you really have to override any DocumentWindow methods, make sure your
           subclass also calls the superclass's method.
        */

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    juce::File appDirectory;
    RootProperties rootProperties;
    ValueTreeFile persitentPropertiesFile;
    PersistentRootProperties persistentRootProperties;
    AppProperties appProperties;
    RuntimeRootProperties runtimeRootProperties;
    Assimil8orValidator assimil8orValidator;
    PresetProperties presetProperties;
    std::unique_ptr<juce::FileLogger> fileLogger;
    std::atomic<RuntimeRootProperties::QuitState> localQuitState { RuntimeRootProperties::QuitState::idle };
    std::unique_ptr<MainWindow> mainWindow;
};

// This macro generates the main () routine that launches the app.
START_JUCE_APPLICATION (A8ManagerApplication)

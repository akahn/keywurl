/*
 *     Generated by class-dump 3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */



/*
 * File: /Applications/Safari.app/Contents/MacOS/Safari
 * Arch: Intel x86-64 (x86_64)
 *
 *       Objective-C Garbage Collection: Unsupported
 */

@interface WebViewPlus : WebView
{
    BOOL _bannerIsMovingIntoPlace;
    NSMutableArray *_currentBanners;
    NSMutableArray *_bannerActionQueue;
}

- (void)dealloc;
- (void)close;
- (BOOL)maintainsInactiveSelection;
- (void)bannerDidInstall:(id)arg1;
- (void)bannerDidUninstall:(id)arg1;
- (void)bannerWillInstall:(id)arg1;
- (void)bannerWillUninstall:(id)arg1;
- (void)banner:(id)arg1 viewBelow:(id)arg2 wasResizedFromFrame:(struct CGRect)arg3 animationProgress:(float)arg4 installing:(BOOL)arg5;
- (id)viewBelowBanner:(id)arg1;
- (id)currentBanners;
- (void)queueInstallOfBanner:(id)arg1 allowingAnimation:(BOOL)arg2;
- (void)queueUninstallOfBanner:(id)arg1 allowingAnimation:(BOOL)arg2;
- (void)zoomIn:(id)arg1;
- (void)zoomOut:(id)arg1;
- (void)zoomToStandardSize:(id)arg1;
- (BOOL)canZoomIn;
- (BOOL)canZoomOut;
- (BOOL)canZoomToStandardSize;
- (float)zoomMultiplier;
- (void)setZoomMultiplier:(float)arg1;
- (id)currentURL;

@end

@interface SearchableWebView : WebViewPlus
{
    id _findInPageBanner;
}

- (id)findInPageBanner;
- (BOOL)isShowingFindInPageBanner;
- (BOOL)canFocusSearchField;
- (BOOL)canShowFindInPageBanner;
- (BOOL)canHideFindInPageBanner;
- (BOOL)canFindNext;
- (void)findNext;
- (BOOL)canFindPrevious;
- (void)findPrevious;
- (unsigned long long)matchCountForString:(id)arg1 limit:(unsigned long long)arg2;
- (BOOL)findBanner:(id)arg1 doSearchFieldCommandBySelector:(SEL)arg2;
- (void)findInPageBannerNeedsUpdateInRect:(struct CGRect)arg1;
- (BOOL)currentPageIsSearchable;
- (void)showFindInPageBannerAllowingAnimation:(BOOL)arg1;
- (void)hideFindInPageBannerAllowingAnimation:(BOOL)arg1;
- (void)focusSearchField;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1 frameName:(id)arg2 groupName:(id)arg3;
- (void)close;
- (void)awakeFromNib;
- (void)viewDidMoveToWindow;
- (void)webView:(id)arg1 didDrawRect:(struct CGRect)arg2;
- (void)webView:(id)arg1 didScrollDocumentInFrameView:(id)arg2;

@end

@interface BrowserContentWebView : SearchableWebView
{
    BOOL isObservingAppLaunches;
    id _document;
    NSMutableArray *_iPhotoFileWrappers;
    struct ProcessSerialNumber iPhotoPSN;
}

+ (BOOL)shouldIncludeInWebKitStatistics;
- (id)document;
- (id)browserWindow;
- (id)windowController;
- (id)webFrameForSelectAllCopy;
- (void)webView:(id)arg1 didWriteSelectionToPasteboard:(id)arg2;
- (void)reportErrorForBadFileWrapper:(id)arg1;
- (void)saveFileWrapperToDownloadsFolder:(id)arg1 originatingURL:(id)arg2;
- (id)proposedBookmarkTitleForElement:(id)arg1;
- (id)browserWebView;
- (void)goToURL:(id)arg1;
- (void)_detachAndReattachElementsByTagName:(id)arg1;
- (void)restartPlugins;

@end

@interface BrowserWebView : BrowserContentWebView 
{
    id _loadMonitor;
    NSURLRequest *_initialRequest;
    BOOL _shouldStartEmpty;
    id _searchResultsForSnapBack;
    id bookmarksViewController;
    id bookmarksViewContents;
    NSString *_statusText;
    NSString *_progressStatus;
    id _progressStatusOwner;
    BOOL _ellipsizeProgressStatus;
    NSString *_generalStatus;
    id _generalStatusOwner;
    BOOL _ellipsizeGeneralStatus;
    NSString *_userDrivenStatus;
    id _userStatusOwner;
    BOOL _ellipsizeUserStatus;
    NSString *_provisionalOriginalURLString;
    NSString *_originalURLString;
    NSString *_pendingRSSFeedURLString;
    id _pendingRSSFeedReferrer;
    NSArray *_counterpartURLsForRSS;
    NSString *_requestedTabLabel;
    NSString *_provisionalTabLabel;
    NSString *_committedTabLabel;
    NSArray *_fallbackURLs;
    id _locationChangeDelegate;
    id _sheetRequest;
    id _formDelegate;
    double _redirectDelay;
    double _cumulativeMagnifyDelta;
    short _stickyTextMagnifyGestureDirection;
    float _textSizeMultiplierAtGestureStart;
    BOOL _didReaderAvailabilityCheck;
    BOOL _isLoadingIgnoringQueue;
    BOOL _isLoadingConsideringQueue;
    BOOL _mainDocumentHasLoaded;
    BOOL _mainDocumentDidFirstLayout;
    BOOL _mainDocumentDidFirstVisuallyNonEmptyLayout;
    BOOL _progressIsForMainFrameLoad;
    NSTimer *_detectStallsTimer;
    NSTimer *_stallTimer;
    BOOL _isStalled;
    BOOL _mainFrameLoadEndedInError;
    BOOL _isWindowFocusDisabled;
    BOOL _downloadNextPage;
    int _cachedPageType;
    int _oldPageType;
    BOOL _isShowingRSS;
    BOOL _hasDisplayedValidURL;
    BOOL _registeredForNetworkConfigurationChanges;
    BOOL _isMovingToAnotherWindow;
    BOOL _isSwitchingToBackgroundTab;
    BOOL _restoringTabForUndoClose;
    BOOL _blockedFromKeyViewLoop;
    NSView *_blockedKeyViewLoopProxyView;
    BOOL _securePageHasInsecureContent;
    NSURLRequest *_requestWaitingInQueue;
    NSDictionary *_parentalControlledElement;
    void*_topSitesViewController;
    id _animatingTopSitesView;
    id _topSitesZoomToPageFadeOutOverlay;
    NSViewAnimation *_topSitesZoomToPageFadeOutAnimation;
    BOOL _readerIsAvailable;
    void* _readerController;
    id _webClipBanner;
    BOOL _showingSecurityWarningPage;
    BOOL _loadingSecurityWarningPage;
    id _provisionalSecurityInfo;
    id _historyItemForTabCloseUndo;
    BOOL _isNavigatingViaBackForwardList;
    id _currentPageLoad;
    void* _browserWebView;
}

+ (void)initialize;
+ (void)closeWebViewSoon:(id)arg1;
+ (void)closeAllPendingWebViews;
- (id)initWithDocument:(id)arg1 request:(id)arg2 frameName:(id)arg3;
- (void)dealloc;
- (void)beginGestureWithEvent:(id)arg1;
- (void)magnifyWithEvent:(id)arg1;
- (void)goBack:(id)arg1;
- (void)goForward:(id)arg1;
- (id)sheetRequest;
- (void)setSheetRequest:(id)arg1;
- (void)showFindInPageBannerAllowingAnimation:(BOOL)arg1;
- (BOOL)isShowingWebClipBanner;
- (id)webClipBanner;
- (void)showWebClipBannerAllowingAnimation:(BOOL)arg1;
- (void)hideWebClipBannerAllowingAnimation:(BOOL)arg1;
- (BOOL)currentPageIsSearchable;
- (void)showCertificateSheet:(id)arg1;
- (BOOL)isShowingSecurityWarningPage;
- (id)provisionalSecurityInfo;
- (void)setProvisionalSecurityInfo:(id)arg1;
- (id)securityInfo;
- (void)setSecurityInfo:(id)arg1;
- (void)commitProvisionalSecurityInfo;
- (void)setUpSecurityWarningPage;
- (void)showSecurityWarningPageWithSecurityInfo:(id)arg1;
- (void)hideSecurityWarningPage;
- (void)updateSecurityWarningPageWithSecurityInfo:(id)arg1;
- (void)securityWarningPageLoaded;
- (void)securityWarningPageIgnoreWarningButtonPressed;
- (void)securityWarningPageBackButtonPressed;
- (void)securityWarningPageClosePageButtonPressed;
- (id)securityWarningPageLocalizedStringsURLString;
- (void)setUpSecurityWarningPageController;
- (void)bannerDidInstall:(id)arg1;
- (void)bannerDidUninstall:(id)arg1;
- (void)viewWillMoveToWindow:(id)arg1;
- (void)viewDidMoveToWindow;
- (void)close;
- (id)loadMonitor;
- (id)undoManagerForWebView:(id)arg1;
- (void)webView:(id)arg1 setStatusText:(id)arg2;
- (id)webViewStatusText:(id)arg1;
- (void)pluginErrorSheetEnded:(id)arg1 returnCode:(int)arg2 contextInfo:(void *)arg3;
- (void)showMissingPluginSheet:(id)arg1;
- (BOOL)webView:(id)arg1 didPressMissingPluginButton:(id)arg2;
- (void)webView:(id)arg1 mouseDidMoveOverElement:(id)arg2 modifierFlags:(unsigned long long)arg3;
- (id)webView:(id)arg1 createWebViewWithRequest:(id)arg2 windowFeatures:(id)arg3;
- (void)webView:(id)arg1 frame:(id)arg2 exceededDatabaseQuotaForSecurityOrigin:(id)arg3 database:(id)arg4;
- (void)webView:(id)arg1 decidePolicyForGeolocationRequestFromOrigin:(id)arg2 frame:(id)arg3 listener:(id)arg4;
- (void)_confirmGeolocationPermission:(id)arg1 returnCode:(long long)arg2 contextInfo:(void *)arg3;
- (void)webViewRunModal:(id)arg1;
- (void)webViewClose:(id)arg1;
- (void)webViewShow:(id)arg1;
- (void)webViewFocus:(id)arg1;
- (id)webViewFirstResponder:(id)arg1;
- (void)webView:(id)arg1 makeFirstResponder:(id)arg2;
- (BOOL)webViewAreToolbarsVisible:(id)arg1;
- (void)webView:(id)arg1 setToolbarsVisible:(BOOL)arg2;
- (BOOL)webViewIsStatusBarVisible:(id)arg1;
- (void)webView:(id)arg1 setStatusBarVisible:(BOOL)arg2;
- (BOOL)webViewIsResizable:(id)arg1;
- (void)webView:(id)arg1 setResizable:(BOOL)arg2;
- (id)webContentView;
- (void)webView:(id)arg1 setFrame:(struct CGRect)arg2;
- (struct CGRect)webViewFrame:(id)arg1;
- (void)webView:(id)arg1 setContentRect:(struct CGRect)arg2;
- (struct CGRect)webViewContentRect:(id)arg1;
- (void)webView:(id)arg1 didScrollDocumentInFrameView:(id)arg2;
- (BOOL)_runJavaScriptPanelWithMessage:(id)arg1 initiatedByFrame:(id)arg2 hasCancelButton:(BOOL)arg3 allowAppTermination:(BOOL)arg4;
- (void)webView:(id)arg1 runJavaScriptAlertPanelWithMessage:(id)arg2 initiatedByFrame:(id)arg3;
- (BOOL)webView:(id)arg1 runJavaScriptConfirmPanelWithMessage:(id)arg2 initiatedByFrame:(id)arg3;
- (BOOL)webView:(id)arg1 runBeforeUnloadConfirmPanelWithMessage:(id)arg2 initiatedByFrame:(id)arg3;
- (BOOL)webViewShouldInterruptJavaScript:(id)arg1;
- (id)webView:(id)arg1 runJavaScriptTextInputPanelWithPrompt:(id)arg2 defaultText:(id)arg3 initiatedByFrame:(id)arg4;
- (void)webView:(id)arg1 runOpenPanelForFileButtonWithResultListener:(id)arg2 allowMultipleFiles:(BOOL)arg3;
- (void)webView:(id)arg1 saveFrameView:(id)arg2 showingPanel:(BOOL)arg3;
- (void)openPanelDidEnd:(id)arg1 returnCode:(int)arg2 contextInfo:(void *)arg3;
- (BOOL)isMovingToAnotherWindow;
- (void)setMovingToAnotherWindow:(BOOL)arg1;
- (void)didMoveToDocument:(id)arg1;
- (BOOL)disallowCachingSnapshot;
- (BOOL)disallowCachingText;
- (void)newBookmarkSheetDidEnd:(BOOL)arg1;
- (BOOL)_handleErrorPageLink:(id)arg1 fromFrame:(id)arg2;
- (void)webView:(id)arg1 unableToImplementPolicyWithError:(id)arg2 frame:(id)arg3;
- (void)networkConfigurationDidChange:(id)arg1;
- (void)showErrorPageForURL:(id)arg1 withTitle:(id)arg2 message:(id)arg3 errorPageTemplate:(int)arg4;
- (void)webView:(id)arg1 decidePolicyForMIMEType:(id)arg2 request:(id)arg3 frame:(id)arg4 decisionListener:(id)arg5;
- (BOOL)webView:(id)arg1 shouldGoToHistoryItem:(id)arg2;
- (void)webView:(id)arg1 decidePolicyForNavigationAction:(id)arg2 request:(id)arg3 frame:(id)arg4 decisionListener:(id)arg5;
- (void)webView:(id)arg1 decidePolicyForNewWindowAction:(id)arg2 request:(id)arg3 newFrameName:(id)arg4 decisionListener:(id)arg5;
- (id)originalURLString;
- (void)setOriginalURLString:(id)arg1;
- (id)provisionalOriginalURLString;
- (void)setProvisionalOriginalURLString:(id)arg1;
- (id)pendingRSSFeedURLString;
- (id)pendingRSSFeedReferrer;
- (void)setPendingRSSFeedURLString:(id)arg1 withReferrer:(id)arg2;
- (id)provisionalTabLabel;
- (void)setProvisionalTabLabel:(id)arg1;
- (id)committedTabLabel;
- (void)setCommittedTabLabel:(id)arg1;
- (id)requestedTabLabel;
- (void)setRequestedTabLabel:(id)arg1;
- (id)tabLabel;
- (id)statusMessage;
- (BOOL)ellipsizeStatusMessage;
- (id)mouseoverTextForElement:(id)arg1 modifierFlags:(unsigned int)arg2;
- (void)setStatus:(id)arg1 withPriority:(int)arg2 ellipsize:(BOOL)arg3 owner:(id)arg4;
- (void)clearAllStatus;
- (id)currentURL;
- (id)expectedOrCurrentURL;
- (id)expectedOrCurrentOriginalURLString;
- (BOOL)isNavigatingViaBackForwardList;
- (BOOL)isDisplayingCompleteNonRSSPage;
- (BOOL)isDisplayingNonRSSPage;
- (BOOL)isShowingBookmarks;
- (BOOL)isShowingEmptyPage;
- (BOOL)isShowingSecurePage;
- (BOOL)securePageHasInsecureContent;
- (void)setSecurePageHasInsecureContent:(BOOL)arg1;
- (BOOL)isShowingTopSites;
- (BOOL)isShowingTopSitesWall;
- (BOOL)isShowingFullWindowCoverFlow;
- (BOOL)isDisposable;
- (void)hideBookmarks;
- (void)showBookmarks;
- (id)currentTopSitesView;
- (struct TopSitesViewController *)topSitesViewController;
- (BOOL)canShowTopSitesWall;
- (void)showTopSitesWall:(id)arg1;
- (void)topSitesViewWillBecomeSubview:(id)arg1;
- (void)topSitesZoomToPageAnimationDidEnd;
- (void)topSitesZoomToPageAnimationWillStart;
- (void)topSitesSnapshotFetchingStatusHasChanged;
- (void)topSitesModeHasChanged;
- (id)bookmarksViewContents;
- (id)bookmarksViewController;
- (id)locationFieldURL;
- (id)titleForLocationFieldURL;
- (id)URLForNewBookmark;
- (id)titleForNewBookmark;
- (id)currentTitle;
- (id)failedOrCurrentURL;
- (id)pageNameURL;
- (id)pageName;
- (id)displayName;
- (id)fallbackURLs;
- (void)clearFallbackURLs;
- (void)goToNextFallbackURL;
- (BOOL)isLoading;
- (BOOL)isShowingLoadErrorPage;
- (BOOL)isStalled;
- (BOOL)tabShouldDisplayProgressIndicator;
- (BOOL)containsEditedForm;
- (struct FormCompletionController *)activeFormCompletionController;
- (void)setMainFrameLoadEndedInError:(BOOL)arg1;
- (BOOL)mainFrameLoadEndedInError;
- (void)setMainDocumentHasLoaded:(BOOL)arg1;
- (BOOL)mainDocumentHasLoaded;
- (void)setMainDocumentDidFirstLayout:(BOOL)arg1;
- (BOOL)mainDocumentDidFirstLayout;
- (void)setMainDocumentDidFirstVisuallyNonEmptyLayout:(BOOL)arg1;
- (BOOL)mainDocumentDidFirstVisuallyNonEmptyLayout;
- (void)progressChanged:(id)arg1;
- (void)progressFinished:(id)arg1;
- (void)setPendingRedirectDelay:(double)arg1;
- (void)cancelPendingRedirect;
- (double)pendingRedirectDelay;
- (unsigned long long)draggingUpdated:(id)arg1;
- (BOOL)canMakeTextSmaller;
- (BOOL)canMakeTextLarger;
- (BOOL)canMakeTextStandardSize;
- (BOOL)canZoomPageIn;
- (BOOL)canZoomPageOut;
- (BOOL)canResetPageZoom;
- (void)zoomIn:(id)arg1;
- (void)zoomOut:(id)arg1;
- (void)zoomToStandardSize:(id)arg1;
- (BOOL)isSwitchingToBackgroundTab;
- (void)setSwitchingToBackgroundTab:(BOOL)arg1;
- (BOOL)maintainsInactiveSelection;
- (BOOL)isShowingRSS;
- (id)counterpartURLsForRSS;
- (void)updateCounterpartURLsForRSS;
- (void)snapBackTo:(id)arg1;
- (void)animationDidEnd:(id)arg1;
- (void)setSearchResultsForSnapBack:(id)arg1;
- (void)setSearchResultsForSnapBackToCurrentPage;
- (void)clearSearchResultsForSnapBack;
- (BOOL)canSnapBackToSearchResults;
- (void)snapBackToSearchResults:(id)arg1;
- (id)searchResultsForSnapBack;
- (void)goNowIfInQueue;
- (void)stopLoading:(id)arg1;
- (void)_fetchSnapshots;
- (void)_promptToFetchRecentHistoryPreviews;
- (void)_confirmFetchWebpagePreviews:(id)arg1 returnCode:(int)arg2 contextInfo:(id)arg3;
- (BOOL)_performSpecialReloadActions;
- (void)reload:(id)arg1;
- (void)reloadFromOrigin:(id)arg1;
- (BOOL)canReload;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (void)setAcceptsGenericIcon:(BOOL)arg1;
- (void)updateIcon;
- (void)nameHasChanged;
- (void)pageTitleHasChanged;
- (void)locationFieldURLHasChanged;
- (void)prepareForRSSAnimation;
- (void)currentURLHasChanged;
- (void)provisionalDataSourceLoadDidFail;
- (void)provisionalURLHasChanged;
- (void)pageLoadingStatusHasChanged;
- (void)dataSourceHasChanged:(id)arg1 forFrame:(id)arg2;
- (void)mainDataSourceHasChanged;
- (void)goToRequest:(id)arg1 withTabLabel:(id)arg2 allowJavaScript:(BOOL)arg3 waitInQueue:(BOOL)arg4;
- (void)goToURL:(id)arg1;
- (void)tryMultipleURLs:(id)arg1;
- (void)tryDownloadWithMultipleURLs:(id)arg1;
- (id)stringByEvaluatingJavaScriptFromString:(id)arg1;
- (BOOL)hasInitialContents;
- (void)displayInitialContents;
- (BOOL)shouldStartEmpty;
- (void)setShouldStartEmpty;
- (void)clearPageCache;
- (struct CGImage *)generateSnapshotOfType:(int)arg1;
- (BOOL)isWindowFocusDisabled;
- (void)setWindowFocusDisabled:(BOOL)arg1;
- (void)setBlockedFromKeyViewLoop:(BOOL)arg1;
- (void)setBlockedFromKeyViewLoop:(BOOL)arg1 proxyView:(id)arg2;
- (id)blockedKeyViewLoopProxyView;
- (BOOL)isBlockedFromKeyViewLoop;
- (void)setHoverFeedbackSuspended:(BOOL)arg1;
- (id)currentPageLoad;
- (void)setCurrentPageLoad:(id)arg1;
- (id)browserWebView;
- (BOOL)isReaderAvailable;
- (BOOL)isReaderAvailabilityCheckPermitted;
- (void)checkForReaderAvailability;
- (void)deactivateReaderWithAnimation:(BOOL)arg1;
- (BOOL)isShowingReader;
- (BOOL)canToggleReader;
- (struct ReaderController *)readerController;
- (void)setReaderController:(void*)arg1;
- (id)readerWindow;
- (void)readerDidActivate;
- (void)readerWillDeactivate;
- (void)readerDidDeactivate;
- (void)readerDidChangeAvailabilityState;
- (void)readerDidChangeNextPageLoadingState;
- (void)sessionStateDidChange;
- (struct SBrowserWebView *)safariBrowserWebView;



@end

@interface WindowController : NSWindowController 
{
    NSString *_multiWindowFrameAutosaveName;
    BOOL _autosaveFrame;
    BOOL _lastResizeWasProgrammatic;
}

- (void)dealloc;
- (void)_saveFrameIfAllowed;
- (void)windowDidMove:(id)arg1;
- (void)windowDidResize:(id)arg1;
- (void)_safari_windowDidEndLiveResize;
- (void)windowWillClose:(id)arg1;
- (BOOL)setMultiWindowFrameAutosaveName:(id)arg1;
- (id)multiWindowFrameAutosaveName;
- (void)_setFrameWithoutAutosaving:(struct CGRect)arg1 programmatically:(BOOL)arg2;
- (void)setFrameWithoutAutosaving:(struct CGRect)arg1;
- (void)setFrameProgrammatically:(struct CGRect)arg1;
- (BOOL)lastResizeWasProgrammatic;
- (struct CGRect)defaultFrame;
- (void)setFrameToDefault;
- (void)_windowDidLoad;
- (void)setFrameAutosaveEnabled:(BOOL)arg1;
- (BOOL)frameAutosaveEnabled;
- (BOOL)frameAutosaveIsAllowed;

@end

@interface BrowserWindowController : WindowController 
{
    id favoritesBarView;
    NSButton *toggleBookmarksButton;
    id tabBarView;
    id tabBarEnclosureView;
    NSTabView *tabSwitcher;
    id statusBar;
    NSTextField *statusTextField;
    id _toolbarController;
    id _locationFieldEditor;
    id _searchFieldEditor;
    id _statusStringView;
    void* _URLCompletionController;
    void* _searchCompletionController;
    NSMenu *_dynamicBackMenu;
    NSMenu *_dynamicForwardMenu;
    BOOL _isLoading;
    BOOL _temporaryLocationBar;
    BOOL _editedLocationField;
    BOOL _editedLocationFieldWhileLoading;
    BOOL _focusedLocationFieldWhileLoading;
    BOOL _tabBarHiddenByJavaScript;
    BOOL _readyToUpdateKeyboardLoop;
    BOOL _windowIsClosing;
    BOOL _showingPrivateBrowsingConfirmationSheet;
    NSMutableArray *_topLevelViewOrder;
    NSMutableDictionary *_viewHeightsForResizing;
    BOOL _acceptsGenericIcon;
    NSString *_statusText;
    BOOL _clearStatus;
    BOOL _ellipsizeStatus;
    NSString *_newStatus;
    BOOL _stopAndReloadButtonWillStop;
    BOOL _stopAndReloadButtonIsForTopSites;
    BOOL _tabBarShownForTabDrag;
    BOOL _confirmUnsubmittedFormText;
    BOOL _isAutoFilling;
    BOOL _hideToolbarOnEndSheet;
    BOOL _keepTabBarHiddenWhenCreatingTab;
    NSTabView *_tabSwitcherForGoBack;
    NSTabView *_tabSwitcherForGoForward;
    NSMutableArray *_visitedTabs;
    NSMutableArray *_visitedTabsForGoBackTabSwitcher;
    NSMutableArray *_visitedTabsForGoForwardTabSwitcher;
    unsigned int _coalescedUpdateMask;
    BOOL _performingCoalescedUpdates;
    unsigned int _postponedToolbarUpdateMask;
    BOOL _postponeToolbarUpdates;
    BOOL _RSSTransitionSlowMotion;
    id _RSSTransitionImageView;
    NSTimer *_RSSTransitionTimer;
    double _RSSTransitionStartTime;
    double _RSSTransitionDuration;
    BOOL _RSSTransitionInProgress;
    BOOL _startRSSAnimationAfterFirstLayout;
    id _closedTabStateHolder;
    NSTimer *_springToFrontTimer;
    NSTimer *_setStatusMessageTimer;
    void* m_notifier;
    void* _extensionToolbarClientAdapter;
    void *_extensionBars[3];
    id _topExtensionDivider;
    id _bottomExtensionDivider;
    void* m_browserWindow;
    id _closingTabView;
}

+ (int)windowPolicyFromEventModifierFlags:(unsigned int)arg1 isMiddleMouseButton:(BOOL)arg2 requireCommandKey:(BOOL)arg3;
+ (int)windowPolicyFromEventModifierFlags:(unsigned int)arg1 isMiddleMouseButton:(BOOL)arg2;
+ (int)windowPolicyFromEventModifierFlags:(unsigned int)arg1 requireCommandKey:(BOOL)arg2;
+ (int)windowPolicyFromCurrentEventRequireCommandKey:(BOOL)arg1;
+ (int)windowPolicyFromCurrentEvent;
+ (int)windowPolicyFromCurrentEventRespectingKeyEquivalents:(BOOL)arg1;
+ (int)windowPolicyFromNavigationAction:(const struct SWebNavigationAction *)arg1;
+ (void)reopen;
+ (id)browserWindowControllerForWindow:(id)arg1;
- (void)addBookmark:(id)arg1;
- (void)autoFill:(id)arg1;
- (void)changeTextEncoding:(id)arg1;
- (void)closeCurrentTab:(id)arg1;
- (void)closeInactiveTabs:(id)arg1;
- (void)goBackAndFlashToolbarButton:(id)arg1;
- (void)goBack:(id)arg1;
- (void)goBackOrForwardFromSegmentedControl:(id)arg1;
- (void)goForwardAndFlashToolbarButton:(id)arg1;
- (void)goForward:(id)arg1;
- (void)goHome:(id)arg1;
- (void)goToToolbarLocation:(id)arg1;
- (void)zoomIn:(id)arg1;
- (void)zoomOut:(id)arg1;
- (void)zoomInOrOutFromSegmentedControl:(id)arg1;
- (void)zoomToStandardSize:(id)arg1;
- (void)moveCurrentTabToNewWindow:(id)arg1;
- (void)newBookmarkFolder:(id)arg1;
- (void)newTab:(id)arg1;
- (id)_localSearchStringFromWebSearchString:(id)arg1;
- (void)performQuickSearch:(id)arg1;
- (void)searchProviderConfirmationDidEnd:(id)arg1 returnCode:(int)arg2 contextInfo:(void *)arg3;
- (void)printFromToolbar:(id)arg1;
- (void)reportBugToApple:(id)arg1;
- (void)selectLocationField:(id)arg1;
- (void)selectNextTab:(id)arg1;
- (void)selectPreviousTab:(id)arg1;
- (void)selectSearchField:(id)arg1;
- (void)stopOrReload:(id)arg1;
- (void)stopLoading:(id)arg1;
- (BOOL)canReloadObeyingLocationField;
- (void)reloadObeyingLocationField:(id)arg1;
- (void)closeTabFromMenu:(id)arg1;
- (void)closeOtherTabsFromMenu:(id)arg1;
- (void)moveTabToNewWindowFromMenu:(id)arg1;
- (void)reloadTabFromMenu:(id)arg1;
- (void)reloadAllTabs:(id)arg1;
- (void)showBookmarksView:(id)arg1;
- (void)showHistoryInBookmarksView:(id)arg1;
- (void)toggleLocationBar:(id)arg1;
- (void)toggleFavoritesBar:(id)arg1;
- (void)toggleExtensionBar:(id)arg1;
- (void)toggleStatusBar:(id)arg1;
- (void)toggleShowBookmarks:(id)arg1;
- (void)toggleTabBar:(id)arg1;
- (void)toggleReader:(id)arg1;
- (void)createWebClip:(id)arg1;
- (void)showTopSitesWall:(id)arg1;
- (BOOL)canReloadTab:(id)arg1;
- (BOOL)canReloadAllTabs;
- (BOOL)canCloseSelectedTab;
- (BOOL)canCreateNewTab;
- (BOOL)canShowTopSitesWall;
- (void)noResponderFor:(SEL)arg1;
- (void)cancel:(id)arg1;
- (id)windowNibName;
- (void)windowWillLoad;
- (void)windowDidLoad;
- (void)showWindow:(id)arg1;
- (void)setDocument:(id)arg1;
- (BOOL)shouldCloseDocument;
- (struct CGRect)defaultFrame;
- (BOOL)isLocationBarVisible;
- (void)setLocationBarVisible:(BOOL)arg1;
- (BOOL)isFavoritesBarVisible;
- (void)setFavoritesBarVisible:(BOOL)arg1;
- (BOOL)isTabBarVisible;
- (void)setTabBarVisible:(BOOL)arg1;
- (BOOL)isStatusBarVisible;
- (void)setStatusBarVisible:(BOOL)arg1;
- (BOOL)anyToolbarsVisible;
- (void)setToolbarsVisible:(BOOL)arg1;
- (struct CGRect)adjustedFrameForSaving:(struct CGRect)arg1;
- (struct CGRect)adjustedFrameForCascade:(struct CGRect)arg1 fromWindow:(id)arg2;
- (BOOL)isAvailableForForcedLocationUsingWindowPolicy:(int)arg1;
- (BOOL)allowBookmarksChanges;
- (void)editAddressOfFavorite:(id)arg1;
- (void)editContentsOfFavorite:(id)arg1;
- (void)editTitleOfFavorite:(id)arg1;
- (id)favoritesBarView;
- (void)revealFavorite:(id)arg1;
- (void)deleteBookmark:(id)arg1;
- (void)editTitleOfBookmarksCollection:(id)arg1;
- (BOOL)acceptsGenericIcon;
- (void)setAcceptsGenericIcon:(BOOL)arg1;
- (void)setSearchFieldText:(id)arg1;
- (void)_searchForStringWithoutUpdatingRecentSearches:(id)arg1;
- (void)searchForString:(id)arg1;
- (BOOL)toolbarInputFieldsIncludeSearchField;
- (id)toolbarWindow;
- (id)dynamicBackMenu;
- (id)dynamicForwardMenu;
- (id)tabBarView;
- (id)orderedTabs;
- (id)orderedTabViewItems;
- (void)insertInOrderedTabViewItems:(id)arg1;
- (void)insertInOrderedTabViewItems:(id)arg1 atIndex:(unsigned int)arg2;
- (void)replaceInOrderedTabViewItems:(id)arg1 atIndex:(unsigned int)arg2;
- (void)removeFromOrderedTabViewItemsAtIndex:(unsigned int)arg1;
- (id)tabViewItemForWebView:(id)arg1;
- (id)currentBrowserWebView;
- (id)currentBrowserOrOverlayWebView;
- (id)selectedTab;
- (unsigned long long)selectedTabIndex;
- (id)createTab;
- (id)createTabWithFrameName:(id)arg1;
- (id)createTabWithFrameName:(id)arg1 atIndex:(unsigned long long)arg2 andShow:(BOOL)arg3;
- (id)createInactiveTab;
- (id)createInactiveTabWithFrameName:(id)arg1;
- (void)selectTab:(id)arg1;
- (void)closeTab:(id)arg1;
- (void)closeTabOrWindow:(id)arg1;
- (void)closeOtherTabs:(id)arg1;
- (void)reloadTabsMatchingURLs:(id)arg1;
- (void)replaceTabsWithStates:(const void*)arg1 allowGoBack:(BOOL)arg2;
- (void)replaceEmptyTabWithTabs:(id)arg1;
- (void)moveTab:(id)arg1 toIndex:(unsigned int)arg2;
- (void)moveTabFromOtherWindow:(id)arg1 toIndex:(unsigned int)arg2 andShow:(BOOL)arg3;
- (id)tabsWithUnsubmittedFormText;
- (unsigned long long)numberOfNonDisposableTabs;
- (unsigned long long)numberOfTabs;
- (void)updateTabLabelForWebView:(id)arg1;
- (double)tabBarHeight;
- (void)windowTitleNeedsUpdate;
- (void)firstResponderMightHaveChanged;
- (void)willShowCustomizeToolbarSheet;
- (id)windowForSheet;
- (BOOL)isAutoFilling;
- (BOOL)canShowInputFields;
- (id)locationField;
- (id)searchField;
- (struct ExtensionToolbarClientObjCAdapter *)extensionToolbarClient;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (void)windowDidBecomeKey:(id)arg1;
- (void)windowDidEndSheet:(id)arg1;
- (void)windowDidResignKey:(id)arg1;
- (void)windowDidBecomeMain:(id)arg1;
- (void)windowDidResignMain:(id)arg1;
- (struct CGSize)windowWillResize:(id)arg1 toSize:(struct CGSize)arg2;
- (void)windowDidResize:(id)arg1;
- (void)_safari_windowDidEndLiveResize;
- (void)windowDidMove:(id)arg1;
- (void)windowDidMiniaturize:(id)arg1;
- (void)windowDidDeminiaturize:(id)arg1;
- (struct CGRect)windowWillUseStandardFrame:(id)arg1 defaultFrame:(struct CGRect)arg2;
- (void)swipeWithEvent:(id)arg1;
- (BOOL)_formCompletionControllerHandleKeyEvent:(id)arg1;
- (BOOL)window:(id)arg1 performKeyEquivalent:(id)arg2;
- (BOOL)window:(id)arg1 willHandleKeyEvent:(id)arg2;
- (void)doCommandBySelector:(SEL)arg1;
- (BOOL)window:(id)arg1 willHandleMouseDownEvent:(id)arg2;
- (struct CGRect)window:(id)arg1 willPositionSheet:(id)arg2 usingRect:(struct CGRect)arg3;
- (id)windowWillReturnFieldEditor:(id)arg1 toObject:(id)arg2;
- (BOOL)windowShouldClose:(id)arg1;
- (void)_tellAppControllerWindowWillClose;
- (void)windowWillClose:(id)arg1;
- (id)browserWindowTitleBarURL:(id)arg1;
- (void)browserWindow:(id)arg1 shouldGoToURL:(id)arg2;
- (void)controlTextDidChange:(id)arg1;
- (void)controlTextDidEndEditing:(id)arg1;
- (BOOL)control:(id)arg1 textView:(id)arg2 doCommandBySelector:(SEL)arg3;
- (void)locationTextFieldURLDropped:(id)arg1;
- (id)bookmarkTitleForLocationTextField:(id)arg1;
- (BOOL)searchField:(id)arg1 shouldRememberSearchString:(id)arg2;
- (BOOL)searchField:(id)arg1 trackSearchButtonForEvent:(id)arg2 inRect:(struct CGRect)arg3;
- (void)locationTextFieldMarkedTextDidChange:(id)arg1;
- (void)locationTextFieldPerformStopReloadButtonAction:(id)arg1;
- (void)locationTextFieldPerformReaderButtonAction:(id)arg1;
- (void)locationTextFieldPerformRSSButtonAction:(id)arg1;
- (void)locationTextFieldPerformEVCertificateButtonAction:(id)arg1;
- (void)locationTextFieldPerformPrivateBrowsingButtonAction:(id)arg1;
- (void)locationTextField:(id)arg1 mouseUpInPrivateBrowsingButton:(id)arg2;
- (void)locationTextField:(id)arg1 mouseUpInStopReloadButton:(id)arg2;
- (BOOL)locationTextField:(id)arg1 mouseDownInRSSButton:(id)arg2;
- (void)locationTextField:(id)arg1 mouseUpInRSSButton:(id)arg2;
- (void)locationTextField:(id)arg1 mouseUpInReaderButton:(id)arg2 shouldShowContextMenu:(BOOL)arg3;
- (void)locationTextField:(id)arg1 mouseUpInEVCertificateButton:(id)arg2;
- (void)menuNeedsUpdate:(id)arg1;
- (BOOL)menuHasKeyEquivalent:(id)arg1 forEvent:(id)arg2 target:(id *)arg3 action:(SEL *)arg4;
- (unsigned long long)morphingDragImage:(id)arg1 draggingEntered:(id)arg2;
- (unsigned long long)morphingDragImage:(id)arg1 draggingUpdated:(id)arg2;
- (void)morphingDragImage:(id)arg1 draggingExited:(id)arg2;
- (BOOL)morphingDragImage:(id)arg1 performDragOperation:(id)arg2;
- (void)morphingDragImage:(id)arg1 enteredWindow:(id)arg2;
- (void)morphingDragImage:(id)arg1 exitedWindow:(id)arg2;
- (void)willSelectTabViewItem;
- (void)didSelectTabViewItem;
- (void)tabBarViewDidRearrangeTabsWithOldSelectedTabIndex:(unsigned long long)arg1;
- (void)updateTabTitlesSoon;
- (void)cancelUpdateTabTitlesSoon;
- (void)mainDocumentDidFirstVisuallyNonEmptyLayout;
- (void)webViewProgressHasStarted:(id)arg1;
- (void)webViewProgressValueHasChanged:(id)arg1;
- (void)webViewProgressHasFinished:(id)arg1;
- (void)webViewProgressHasStalled:(id)arg1;
- (void)webViewSheetRequestStatusHasChanged:(id)arg1;
- (void)webViewStatusMessageHasChanged:(id)arg1;
- (void)webViewLocationFieldURLHasChanged:(id)arg1;
- (void)webViewLocationFieldIconHasChanged:(id)arg1;
- (void)webViewMainDocumentHasLoaded:(id)arg1;
- (void)webViewLoadingStatusHasChanged:(id)arg1;
- (void)webViewReloadabilityHasChanged:(id)arg1;
- (void)webViewNameHasChanged:(id)arg1;
- (void)webViewBannerHasChanged:(id)arg1;
- (void)webViewFormEditedStatusHasChanged:(id)arg1;
- (void)webViewBlockedFromKeyViewLoopHasChanged:(id)arg1;
- (void)webViewSecureContentStatusHasChanged:(id)arg1;
- (void)webViewDidUpdateReaderAvailability:(id)arg1;
- (void)webViewReaderDidActivate:(id)arg1;
- (void)webViewReaderWillDeactivate:(id)arg1;
- (void)webViewReaderDidDeactivate:(id)arg1;
- (void)webViewReaderDidChangeNextPageLoadingState:(id)arg1;
- (void)webFrameLoadStarted:(id)arg1;
- (void)webFrameLoadCommitted:(id)arg1;
- (void)webViewMainDocumentDidFirstLayout:(id)arg1;
- (void)webFrameLoadFinished:(id)arg1 withError:(id)arg2;
- (void)webFrame:(id)arg1 willPerformClientRedirectToURL:(id)arg2;
- (void)dealloc;
- (BOOL)closeKeyEquivalentClosesTab;
- (void)bar:(struct ExtensionBar *)arg1 handleNavigationAction:(const struct SWebNavigationAction *)arg2 request:(const struct SWebURLRequest *)arg3;
- (struct SBrowserWindow *)browserWindowForBar:(const struct ExtensionBar *)arg1;
- (struct SBrowserWindow *)browserWindowForToolbarItem:(const struct ExtensionToolbarItem *)arg1;
- (void)bar:(struct ExtensionBar *)arg1 showWithAnimation:(BOOL)arg2;
- (void)bar:(struct ExtensionBar *)arg1 hideWithAnimation:(BOOL)arg2;
- (struct SBrowserWindow *)safariBrowserWindow;
- (void)sessionStateDidChange;
- (BOOL)shouldReaderIgnoreWindowChangeNotificationsForWebView:(id)arg1;



@end

@interface TextFieldEditor : NSTextView
{
    BOOL _pasteReplacesLineEndingsWithSpaces;
}

- (id)init;
- (BOOL)pasteReplacesLineEndingsWithSpaces;
- (void)setPasteReplacesLineEndingsWithSpaces:(BOOL)arg1;
- (void)replaceCarriageReturnsAfterPaste;
- (void)paste:(id)arg1;
- (void)pasteAsPlainText:(id)arg1;
- (void)doCommandBySelector:(SEL)arg1;

@end

@interface LocationFieldEditor : TextFieldEditor
{
@public
    id field;
    NSString *_previousMarkedText;
}

- (id)initWithField:(id)arg1;
- (void)dealloc;
- (unsigned long long)validModesForFontPanel:(id)arg1;
- (void)changeFont:(id)arg1;
- (id)acceptableDragTypes;
- (unsigned long long)draggingEntered:(id)arg1;
- (unsigned long long)draggingUpdated:(id)arg1;
- (BOOL)prepareForDragOperation:(id)arg1;
- (BOOL)performDragOperation:(id)arg1;
- (void)concludeDragOperation:(id)arg1;
- (void)_notifyFieldIfMarkedTextDidChange;
- (void)didChangeText;
- (void)setMarkedText:(id)arg1 selectedRange:(struct _NSRange)arg2;
- (void)smartInsertForString:(id)arg1 replacingRange:(struct _NSRange)arg2 beforeString:(id *)arg3 afterString:(id *)arg4;

@end


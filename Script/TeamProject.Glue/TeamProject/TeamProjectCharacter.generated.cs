using UnrealSharp.Attributes;
using UnrealSharp.Core.Attributes;
using UnrealSharp.Interop;
using UnrealSharp.Core.Marshallers;

namespace UnrealSharp.TeamProject;

[UClass, GeneratedType("TeamProjectCharacter", "UnrealSharp.TeamProject.TeamProjectCharacter")]
public partial class ATeamProjectCharacter : UnrealSharp.Engine.ACharacter
{
    static readonly IntPtr NativeClassPtr;
    static ATeamProjectCharacter()
    {
        NativeClassPtr = UCoreUObjectExporter.CallGetNativeClassFromName(typeof(ATeamProjectCharacter).GetAssemblyName(), "UnrealSharp.TeamProject", "TeamProjectCharacter");
        IntPtr CameraBoom_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "CameraBoom");
        CameraBoom_Offset = FPropertyExporter.CallGetPropertyOffset(CameraBoom_NativeProperty);
        IntPtr FollowCamera_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "FollowCamera");
        FollowCamera_Offset = FPropertyExporter.CallGetPropertyOffset(FollowCamera_NativeProperty);
        IntPtr DefaultMappingContext_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "DefaultMappingContext");
        DefaultMappingContext_Offset = FPropertyExporter.CallGetPropertyOffset(DefaultMappingContext_NativeProperty);
        IntPtr JumpAction_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "JumpAction");
        JumpAction_Offset = FPropertyExporter.CallGetPropertyOffset(JumpAction_NativeProperty);
        IntPtr MoveAction_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "MoveAction");
        MoveAction_Offset = FPropertyExporter.CallGetPropertyOffset(MoveAction_NativeProperty);
        IntPtr LookAction_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "LookAction");
        LookAction_Offset = FPropertyExporter.CallGetPropertyOffset(LookAction_NativeProperty);
    }
    
    static int CameraBoom_Offset;
    
    /// <summary>
    /// Camera boom positioning the camera behind the character
    /// </summary>
    public UnrealSharp.Engine.USpringArmComponent CameraBoom
    {
        get
        {
            return ObjectMarshaller<UnrealSharp.Engine.USpringArmComponent>.FromNative(IntPtr.Add(NativeObject, CameraBoom_Offset), 0);
        }
    }
    
    
    static int FollowCamera_Offset;
    
    /// <summary>
    /// Follow camera
    /// </summary>
    public UnrealSharp.Engine.UCameraComponent FollowCamera
    {
        get
        {
            return ObjectMarshaller<UnrealSharp.Engine.UCameraComponent>.FromNative(IntPtr.Add(NativeObject, FollowCamera_Offset), 0);
        }
    }
    
    
    static int DefaultMappingContext_Offset;
    
    /// <summary>
    /// MappingContext
    /// </summary>
    public UnrealSharp.EnhancedInput.UInputMappingContext DefaultMappingContext
    {
        get
        {
            return ObjectMarshaller<UnrealSharp.EnhancedInput.UInputMappingContext>.FromNative(IntPtr.Add(NativeObject, DefaultMappingContext_Offset), 0);
        }
    }
    
    
    static int JumpAction_Offset;
    
    /// <summary>
    /// Jump Input Action
    /// </summary>
    public UnrealSharp.EnhancedInput.UInputAction JumpAction
    {
        get
        {
            return ObjectMarshaller<UnrealSharp.EnhancedInput.UInputAction>.FromNative(IntPtr.Add(NativeObject, JumpAction_Offset), 0);
        }
    }
    
    
    static int MoveAction_Offset;
    
    /// <summary>
    /// Move Input Action
    /// </summary>
    public UnrealSharp.EnhancedInput.UInputAction MoveAction
    {
        get
        {
            return ObjectMarshaller<UnrealSharp.EnhancedInput.UInputAction>.FromNative(IntPtr.Add(NativeObject, MoveAction_Offset), 0);
        }
    }
    
    
    static int LookAction_Offset;
    
    /// <summary>
    /// Look Input Action
    /// </summary>
    public UnrealSharp.EnhancedInput.UInputAction LookAction
    {
        get
        {
            return ObjectMarshaller<UnrealSharp.EnhancedInput.UInputAction>.FromNative(IntPtr.Add(NativeObject, LookAction_Offset), 0);
        }
    }
    
    
}